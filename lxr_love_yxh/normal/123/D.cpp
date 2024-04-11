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
int n,maxlen[200005],tr[200005][26],f[200005],par[200005],size,lst,len,ans;
string s;
void extend(int id){
	int cur=++size,p=lst;f[cur]=1;
	maxlen[cur]=maxlen[lst]+1;
	for(p=lst;p&&!tr[p][id];p=par[p])tr[p][id]=cur;
	if(!p)par[cur]=1;
	else{
		int q=tr[p][id];
		if(maxlen[q]==maxlen[p]+1)par[cur]=q;
		else{
			int clone=++size;
			maxlen[clone]=maxlen[p]+1;
			memcpy(tr[clone],tr[q],sizeof tr[q]);
			par[clone]=par[q];
			while(p&&tr[p][id]==q){
				tr[p][id]=clone;
				p=par[p];
			}
			par[cur]=par[q]=clone;
		}
	}
	lst=cur;
}
vector<int>g[200005];
void dfs(int x){
	for(auto to:g[x]){
		dfs(to);f[x]+=f[to];
	}
	if(x!=1)ans+=1ll*f[x]*(f[x]+1)/2*(maxlen[x]-maxlen[par[x]]);
}
void build(){
	for(int i=2;i<=size;i++){
		g[par[i]].push_back(i);
	}
	dfs(1);
}
signed main(){
	size=lst=1;
	cin>>s;
	for(char c:s)extend(c-'a');
	build();
	cout<<ans<<endl;
	return 0;
}