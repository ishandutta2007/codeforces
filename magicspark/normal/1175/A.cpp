//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
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
int t;
signed main(){
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int ans=1;
		while(n!=1){
			if(n<k){
				ans+=n-1;
				n=1;
				break;
			}
			if(n%k){
				ans+=n%k;
				n-=n%k;
			}else{
				ans++;
				n/=k;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}