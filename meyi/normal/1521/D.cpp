#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
struct edge{
	int to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
typedef pair<int,int> pii;
typedef pair<pii,pii> ppp;
#define fi first
#define se second
vector<ppp>chain;
vector<int>son[maxn];
#define pb push_back
inline pii calc(int p){
	if(son[p].size()>1)return {calc(son[p][0]).se,calc(son[p][1]).se};
	pii ret;
	ret.fi=p;
	while(son[p].size())p=son[p][0];
	ret.se=p;
	return ret;
}
void dfs(int p,int f){
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f)
			dfs(e[i].to,p);
	if(son[p].size()<2)son[f].pb(p);
	else{
		while(son[p].size()>2)chain.pb(ppp(pii(p,son[p].back()),calc(son[p].back()))),son[p].pop_back();
		chain.pb(ppp(pii(f,p),calc(p)));
	}
}
int n,t;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		len=0;
		memset(hd,0,sizeof hd);
		son[0].clear();
		for(ri i=1,x,y;i<n;++i){
			scanf("%d%d",&x,&y);
			addedge(x,y),addedge(y,x);
			son[i].clear();
		}
		chain.clear();
		son[n].clear();
		dfs(1,0);
		if(son[0].size())chain.pb(ppp(pii(1,1),calc(0)));
		printf("%d\n",chain.size()-1);
		for(ri i=chain.size()-2;i>=0;--i)printf("%d %d %d %d\n",chain[i].fi.fi,chain[i].fi.se,chain[i+1].se.se,chain[i].se.fi);
	}
	return 0;
}