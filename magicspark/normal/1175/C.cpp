//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int t;
int a[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;++i)cin>>a[i];
		pair<int,int>ans(inf,inf);
		for(int i=1;i<=n-k;i++){
			ans=min(ans,make_pair((a[i+k]-a[i]+1)/2,(a[i]+a[i+k])/2));
		}
		cout<<ans.second<<endl;
	}
	return 0;
}