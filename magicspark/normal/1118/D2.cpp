#include<bits/stdc++.h>
#define int long long
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,m;
int a[222222];
inline bool check(int x){
	int sum=0;
	for(int i=1;i<=n;i++){
		int minus=(i-1)/x;
		sum+=max(0ll,a[i]-minus);
	}
	return sum>=m;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;int sum=0;
	for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
	sort(a+1,a+n+1);reverse(a+1,a+n+1);
	if(sum<m){
		puts("-1");
		return 0;
	}else{
		int l=0,r=n;
		while(r-l>1){
			int mid=l+r>>1;
			if(check(mid))r=mid;
			else l=mid;
		}
		cout<<r<<endl;
	}
	return 0;
}