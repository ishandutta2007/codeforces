#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int e1[400005];
int e2[400005];
int b[400005];
int d[400005];
int c[400005];
bool isb[400005];
bool o[400005];
bool ao[400005];
int nn[400005];
int q[400005];
int f[400005];
vector<int> g[400005];
vector<pair<int,int> > g2[400005];
int tt;
int n,m;
int nc;

void dfs(int u, int pe){
	b[u]=d[u]=tt++;
	fore(_,0,g[u].size()){
		int ne=g[u][_];
		if(ne==pe)continue;
		if(!ao[ne]){
			o[ne]=e1[ne]==u;
			ao[ne]=true;
		}
		int v=e1[ne]^e2[ne]^u;
		if(d[v]<0){
			dfs(v,ne);
			if(b[v]>d[u]){
				isb[ne]=true;
			}
			b[u]=min(b[u],b[v]);
		}
		else if(d[v]<d[u])b[u]=min(b[u],d[v]);
	}
}

void dfs2(int x, int cc){
	if(c[x]>=0)return;
	c[x]=cc;
	nn[cc]++;
	fore(i,0,g[x].size()){
		int e=g[x][i];
		if(isb[e])continue;
		dfs2(e1[e]^e2[e]^x,cc);
	}
}

bool dfs3(int x, int p, int k){
	q[x]=nn[x];
	f[x]=max(k-q[x],0);
	fore(i,0,g2[x].size()){
		int y=g2[x][i].fst;
		int e=g2[x][i].snd;
		if(y==p)continue;
		if(dfs3(y,x,k)){
			q[x]+=q[y];
			o[e]=c[e1[e]]==x;
			f[x]=max(k-q[x],0);
		}
		else {
			o[e]=c[e2[e]]==x;
		}
	}
	fore(i,0,g2[x].size()){
		int y=g2[x][i].fst;
		if(y==p)continue;
		if(f[y])f[x]=max(f[x],f[y]-q[x]);
	}
	return f[x]==0;
}

bool can(int k){
	return dfs3(0,-1,k);
}

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,m){
		scanf("%d%d",e1+i,e2+i);e1[i]--;e2[i]--;
		g[e1[i]].pb(i);
		g[e2[i]].pb(i);
	}
	memset(d,-1,sizeof(d));
	dfs(0,-1);
	memset(c,-1,sizeof(c));
	fore(i,0,n){
		if(c[i]<0){
			dfs2(i,nc);
			nc++;
		}
	}
	fore(i,0,m){
		if(isb[i]){
			g2[c[e1[i]]].pb(mp(c[e2[i]],i));
			g2[c[e2[i]]].pb(mp(c[e1[i]],i));
		}
	}
	int s=0,e=n+1;
	while(e-s>1){
		int m=(s+e)/2;
		if(can(m))s=m;
		else e=m;
	}
	assert(can(s));
	printf("%d\n",s);
	fore(i,0,m){
		if(o[i])printf("%d %d\n",e1[i]+1,e2[i]+1);
		else printf("%d %d\n",e2[i]+1,e1[i]+1);
	}
	return 0;
}