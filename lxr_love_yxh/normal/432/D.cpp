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
int n,maxlen[200005],tr[200005][26],f[200005],par[200005],size,lst,len;
string s;
set<int>endpos[200005];
void extend(int id){
	int cur=++size,p=lst;f[cur]=1;endpos[cur].insert(++len);
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
vector<int>ask[200005];
int ans[200005];
void build(){
	for(int i=2;i<=size;i++){
		g[par[i]].push_back(i);
	}
}
void dfs(int x){
	int son=-1;
	for(auto to:g[x]){
		dfs(to);f[x]+=f[to];
		if(son==-1||endpos[to].size()>endpos[son].size()){
			son=to;
		}
	}
	if(son!=-1)endpos[x].swap(endpos[son]);
	for(auto to:g[x])if(to!=son){
		for(auto v:endpos[to])endpos[x].insert(v);
	}
	for(auto len:ask[x]){
		if(!endpos[x].count(s.size()))continue;
		if(maxlen[x]>=len&&maxlen[par[x]]<len)ans[len]=f[x];
	}
} 
signed main(){
	memset(ans,-1,sizeof ans);
	size=lst=1;
	cin>>s;
	for(char c:s)extend(c-'A');
	build();
	int cur=1,len=0;
	for(char c:s){
		cur=tr[cur][c-'A'];
		ask[cur].push_back(++len);
	}
	assert(f[cur]==1&&*endpos[cur].begin()==s.size());
	dfs(1);
	int tot=0;
	for(int i=1;i<=s.size();i++)if(~ans[i])tot++;
	cout<<tot<<endl;
	for(int i=1;i<=s.size();i++)if(~ans[i])cout<<i<<" "<<ans[i]<<endl;
	return 0;
}