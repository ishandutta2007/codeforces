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
int mn=1e18,mx=-1,n,k,a,b;
void upd(int x){
	for(int i=0;i<n;i++){
		int l=k*i+x;
		int GCD=__gcd(l,n*k);
		int res=n*k/GCD;
		if(res<=0)continue;
		mx=max(mx,res);
		mn=min(mn,res);
	}
}
signed main(){
	cin>>n>>k>>a>>b;
	upd(a+b);
	upd(a-b);
	upd(b-a);
	upd(-b-a);
	cout<<mn<<" "<<mx<<endl;
	return 0;
}