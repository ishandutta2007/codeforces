/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
int n;
char s[500005];
int stk[500005],pos[500005],sz,fuck[500005];
int tot=0;
signed main(){
	cin>>n;
	scanf("%s",s+1);
	pos[0]=n+1;
	int res=0,ans=0;
	for(int i=n;i>=1;i--){
		if(s[i]=='0')fuck[i]=0;
		else fuck[i]=fuck[i+1]+1;
	}
	int lst=0;
	for(int i=n;i>=1;i--){
		tot=fuck[i];
		if(fuck[i])lst=fuck[i];
		else if(lst){
			ans-=lst*lst-lst*(lst+1)/2;
			sz+=lst-1;int shit=0;
			for(int j=sz-lst+1;j<=sz;j++){
				stk[j]=++shit;pos[j]=i+(shit);
			}
			reverse(stk+sz-lst+1,stk+sz+1);
			reverse(pos+sz-lst+1,pos+sz+1);
			lst=0;
		}
		while(sz>=1&&stk[sz]<=tot){
			ans-=(pos[sz-1]-pos[sz])*stk[sz];sz--;
		}
		stk[++sz]=tot;pos[sz]=i;
//		cerr<<i<<endl;
//		for(int j=1;j<=sz;j++)cerr<<stk[j]<<" ";cerr<<endl;
//		for(int j=1;j<=sz;j++)cerr<<pos[j]<<" ";cerr<<endl;
		ans+=(pos[sz-1]-pos[sz])*stk[sz];
//		cerr<<i<<" "<<ans-tot*tot+tot*(tot+1)/2<<endl;
		res+=ans-tot*tot+tot*(tot+1)/2;
	}
	cout<<res<<endl;
	return 0;
}