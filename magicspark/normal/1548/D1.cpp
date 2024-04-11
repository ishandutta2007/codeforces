/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include<bits/stdc++.h>
#define int long long
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
inline int Rand(){return rand()*32768+rand();}
int n,xx[6005],yy[6005];
int c[6][6];
int x[4]={0,0,2,2};
int y[4]={0,2,0,2};
int f(int a,int b){
	return __gcd(abs(x[a]-x[b]),abs(y[a]-y[b]));
}
int C(int nn,int x){
	int ret=1;
	for(int i=nn-x+1;i<=nn;i++){
		ret*=i;
	}
	for(int i=1;i<=x;i++)ret/=i;
	return ret;
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>xx[i]>>yy[i];
		c[xx[i]%4][yy[i]%4]++;
	}
	int ans=0;
	for(int i=0;i<4;i++){
		for(int j=i;j<4;j++){
			for(int k=j;k<4;k++){
				if((f(i,j)+f(i,k)+f(j,k))%4!=0)continue;
				map<int,int>mp;
				mp[i]++;mp[j]++;mp[k]++;
				int cur=1;
				for(auto p:mp){
					cur*=C(c[x[p.first]][y[p.first]],p.second);
				}
				ans+=cur;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}