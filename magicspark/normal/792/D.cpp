/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
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
#ifndef LOCAL
#define cerr if(0)cout
#endif
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
ll n,q;
ll lowbit(ll x){
	return x&-x;
} 
signed main(){
	cin>>n>>q;
	while(q--){
		int st;string step;
		cin>>st>>step;
		for(int i=0;i<step.size();i++){
			ll t=lowbit(st);
			if(step[i]=='L'){
				st-=t/2;
			}else if(step[i]=='R'){
				st+=t/2;
			}else if(step[i]=='U'){
				if(st==(n+1)/2)continue;
				st-=t;st|=(t<<1);
			}else{
				while(1);
			}
		}
		cout<<st<<endl;
	}
	return 0;
}