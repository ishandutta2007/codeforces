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
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
ll n,m,q;
signed main(){
	cin>>n>>m>>q;
	int Gcd=__gcd(n,m),ln=n/Gcd,lm=m/Gcd;
	cerr<<ln<<" "<<lm<<endl;
	while(q--){
		ll sx,sy,ex,ey;
		cin>>sx>>sy>>ex>>ey;sy--;ey--;
		int ls=sy/(sx==1?ln:lm),le=ey/(ex==1?ln:lm);
//		cerr<<ls<<" "<<le<<endl;
		if(ls==le){
			puts("YES");
		}else{
			puts("NO");
		}
	}
	return 0;
}