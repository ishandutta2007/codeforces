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
map<ll,ll>memory;
int n,m;
ll calc(ll x){
	if(x<0)return 0;
	if(x<m)return 1;
	if(memory.count(x))return memory[x];
	int mid=(x+1)/2;
	int ret=calc(mid-1)*calc(x-mid)%mod;
	for(int i=1;i<=m;i++){
		ret=(ret+(calc(mid-i)*calc(x-m-mid+i))%mod)%mod;
	}
	return memory[x]=ret;
} 
signed main(){
	cin>>n>>m;
	cout<<calc(n)<<endl;
	return 0;
}