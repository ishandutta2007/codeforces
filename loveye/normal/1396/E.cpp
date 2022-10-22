#include<cstdio>
#include<queue>
#include<set>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=1e5+5;
int n,match[N],sft[N];
ll k,mx,mn;
int fir[N],to[N<<1],eds,nxt[N<<1];
void addedge(int u,int v) {
	to[++eds]=v;
	nxt[eds]=fir[u];
	fir[u]=eds;
}
int siz[N],rt;
void getrt(int u,int fa) {
	int res=0;
	siz[u]=1;
	foredge(i,u,v) if(v!=fa) {
		getrt(v,u);
		siz[u]+=siz[v];
		res=max(res,siz[v]);
	}
	res=max(res,n-siz[u]);
	if(res<=n/2) rt=u;
	if(siz[u]&1) mn+=1;
}

int dep[N],val[N],f[N];
struct cmp1 {
	bool operator () (const int &i,const int &j) const {
		return val[i]<val[j]||(val[i]==val[j]&&i<j);
	}
};
struct cmp2 {
	bool operator () (const int &i,const int &j) const {
		return dep[i]<dep[j]||(dep[i]==dep[j]&&i<j);
	}
};
priority_queue<int,vector<int>,cmp1> pq;
priority_queue<int,vector<int>,cmp2> q1[N],q2[N];
set<int> son[N];
void getdep(int u,int fa,int from) {
	mx+=dep[u];
	f[u]=fa;
	siz[u]=1;
	foredge(i,u,v) if(v!=fa) {
		son[u].insert(v);
		dep[v]=dep[u]+1;
		getdep(v,u,from);
		siz[u]+=siz[v];
	}
	q1[from].push(u);
}
int idfn[N],dfc;
void getmatch(int u,int fa) {
	if(match[u]) return;
	idfn[++dfc]=u;
	foredge(i,u,v) if(v!=fa) getmatch(v,u);
}
void getans(int u,int v,int res) {
	getmatch(rt,0);
	fr(i,1,dfc/2) match[match[idfn[i]]=idfn[i+dfc/2]]=idfn[i];
	if(mx-res!=k) {
		int uu=dep[u]==dep[v]?f[u]:v,vv;
		fr(i,1,(k-(mx-res))/2) uu=f[uu];
		vv=match[uu];
		swap(match[u],match[uu]);
		swap(match[v],match[vv]);
	}
	puts("YES");
	fr(i,1,n) if(i<match[i]) printf("%d %d\n",i,match[i]);
	exit(0);
}
int main() {
	scanf("%d%lld",&n,&k);
	for(int i=1,u,v;i<n;++i) {
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	getrt(1,0);
	foredge(i,rt,u) {
		son[rt].insert(u);
		dep[u]=1,getdep(u,rt,u);
		val[u]=siz[u];
		pq.push(u);
	}
	if(k<mn||k>mx||(k-mx&1)) return puts("NO"),0;
	if(k==mx) {
		getmatch(rt,0);
		puts("YES");
		fr(i,1,n/2) printf("%d %d\n",idfn[i],idfn[i+n/2]);
		return 0;
	}
	while(1) {
		int id=pq.top(); pq.pop();
		val[id]-=2; pq.push(id);
		while(q2[id].size()&&q2[id].top()==q1[id].top())
			q1[id].pop(),q2[id].pop();
		int u=q1[id].top(),res=dep[u]-1<<1,v;
		q1[id].pop();
		if(son[f[u]].size()>1) {
			if(*son[f[u]].begin()==u) v=*(++son[f[u]].begin());
			else v=*son[f[u]].begin();
		} else v=f[u];
		q2[id].push(v);
		son[f[u]].erase(u); son[f[v]].erase(v);

		match[match[v]=u]=v;
		if(mx-res<=k) getans(u,v,res);
		mx-=res;
	}
	return 0;
}