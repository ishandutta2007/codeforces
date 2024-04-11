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
char s[1000005];
int nxt[1000005][2],van[1000005];
int to[1000005];
int par[1000005];
int find(int x){
	return x==par[x]?x:par[x]=find(par[x]);
}
int go(int x,int i){
//	cerr<<x<<" "<<i<<" "<<to[x]<<endl;
	if(x>n)return 0;
	x=find(x);
	if(x>n)return 0;
	if(to[x]-x+1>=i){
		return go(x+i,i)+1;
	}else{
		int pos=min(van[x+1],to[x]+1);
		int ret=go(pos,i);
		par[x]=find(pos);
		return ret;
	}
}
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n+1;i++)par[i]=i;
	van[n+1]=n+1;
	for(int i=n;i>=1;i--){
		if(s[i]=='1')nxt[i][0]=0;
		else nxt[i][0]=nxt[i+1][0]+1;
		if(s[i]=='0')nxt[i][1]=0;
		else nxt[i][1]=nxt[i+1][1]+1;
		to[i]=max(i+nxt[i][0]-1,i+nxt[i][1]-1);
		if(s[i]=='?')van[i]=i;
		else van[i]=van[i+1];
	}
	for(int i=1;i<=n;i++){
		printf("%d ",go(1,i));
	}
	return 0;
}