#include<bits/stdc++.h>
#define int long long
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,m,ta,tb,k;
int a[200005],b[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>ta>>tb>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	if(k>=n||k>=m){
		puts("-1");
		return 0;
	}
	int ans=-1;
	for(int A=0;A<n&&A<=k;A++){
		int B=min(m,k-A);
		if(b[m-B]<a[A+1]+ta){
			return puts("-1")&0;
		}
		int tmp=a[A+1]+ta;
		int t=lower_bound(b+1,b+m+1,tmp)-b;
		t+=B;
		ans=max(ans,b[t]+tb);
	}
	cout<<ans<<endl;
	return 0;
}