#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
struct edge{
	int to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
int cnt;
map<string,int>id;
typedef pair<int,int> pii;
#define fi first
#define se second
inline int get_id(const string &k){
	auto it=id.find(k);
	if(it==id.end())return id[k]=++cnt;
	else return it->se;
}
int dep[maxn],fa[maxn],mx[maxn],siz[maxn],son[maxn];
void dfs1(int p){
	dep[p]=mx[p]=dep[fa[p]]+1;
	siz[p]=1;
	for(ri i=hd[p];i;i=e[i].nxt){
		dfs1(e[i].to);
		ckmax(mx[p],mx[e[i].to]);
		siz[p]+=siz[e[i].to];
		if(siz[e[i].to]>siz[son[p]])son[p]=e[i].to;
	}
}
int a[maxn];
set<int>s[maxn];
void dfs3(int p,bool t){
	if(t)s[dep[p]].insert(a[p]);
	else s[dep[p]].clear();
	for(ri i=hd[p];i;i=e[i].nxt)dfs3(e[i].to,t);
}
int ans[maxn];
vector<pii>q[maxn];
void dfs2(int p){
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=son[p]){
			dfs2(e[i].to);
			dfs3(e[i].to,0);
		}
	if(son[p]){
		dfs2(son[p]);
		for(ri i=hd[p];i;i=e[i].nxt)
			if(e[i].to!=son[p])
				dfs3(e[i].to,1);
	}
	s[dep[p]].insert(a[p]);
	for(auto i:q[p])if(dep[p]+i.fi<=mx[p])ans[i.se]=s[dep[p]+i.fi].size();
}
int m,n;
string t;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(ri i=1;i<=n;++i){
		cin>>t>>fa[i];
		a[i]=get_id(t);
		if(fa[i])addedge(fa[i],i);
	}
	cin>>m;
	for(ri i=1,x,y;i<=m;++i){
		cin>>x>>y;
		q[x].emplace_back(y,i);
	}
	for(ri i=1;i<=n;++i)
		if(!fa[i]){
			dfs1(i);
			dfs2(i);
			dfs3(i,0);
		}
	for(ri i=1;i<=m;++i)cout<<ans[i]<<endl;
	return 0;
}