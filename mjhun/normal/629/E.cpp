#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
using namespace std;

typedef long long ll;

vector<int> g[100005];
int f[100005];
int l[100005];
int p[100005][17];
ll ph[100005];
int nh[100005];
ll pv[100005];
int nv[100005];
int n,m;

void dfs(int v){
	nh[v]=1;
	for(int i=0;i<g[v].size();++i){
		int s=g[v][i];
		if(f[s]<0){
			f[s]=v;
			l[s]=l[v]+1;
			dfs(s);
			nh[v]+=nh[s];
			ph[v]+=ph[s]+nh[s];
		}
	}
}

void dfs2(int v){
	for(int i=0;i<g[v].size();++i){
		int s=g[v][i];
		if(s==f[v])continue;
		nv[s]=nv[v]+nh[v]-nh[s];
		pv[s]=ph[v]+nh[v]-ph[s]-2*nh[s]+pv[v]+nv[v];
		dfs2(s);
	}
}

void prepr(){
  int i, j;
  memset(p,-1,sizeof(p));
//the first ancestor of every node i is T[i]
  for (i = 0; i < n; i++)
      p[i][0] = f[i];
//bottom up dynamic programing
  for (j = 1; (1 << j) < n; j++)
     for (i = 0; i < n; i++)
         if (p[i][j - 1] != -1)
             p[i][j] = p[p[i][j - 1]][j - 1];
}

int lca(int p, int q, int P[][17], int *L){
  int tmp, log, i;
   
  //if p is situated on a higher level than q then we swap them
      if (L[p] < L[q])
          tmp = p, p = q, q = tmp;
  
  //we compute the value of [log(L[p)]
      for (log = 1; 1 << log <= L[p]; log++);
      log--;
   
  //we find the ancestor of node p situated on the same level
  //with q using the values in P
      for (i = log; i >= 0; i--)
          if (L[p] - (1 << i) >= L[q])
              p = P[p][i];
   
      if (p == q)
          return p;
   
  //we compute LCA(p, q) using the values in P
      for (i = log; i >= 0; i--)
          if (P[p][i] != -1 && P[p][i] != P[q][i])
              p = P[p][i], q = P[q][i];
   		
      return f[p];
}

double query(int x, int y){
	int z=lca(x,y,p,l);
	if(z!=x&&z!=y){
		return l[x]+l[y]-2*l[z]+1+1.*ph[x]/nh[x]+1.*ph[y]/nh[y];
	}
	else {
		if(x==z)swap(x,y);
		int w=x;
		int log,i;
		for (log = 1; 1 << log <= l[w]; log++);
      	log--;
		for (i = log; i >= 0; i--)
		      if (l[w] - (1 << i) >= l[y]+1)
		          w = p[w][i];
   		assert(l[w]==l[y]+1);
   		return l[x]-l[w]+1+1.*ph[x]/nh[x]+1.*pv[w]/nv[w];
   		return l[x]-l[y]+1+1.*ph[x]/nh[x]+1.*(ph[0]-ph[w]-l[w]*nh[w])/(nh[0]-nh[w]);
   	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;++i){
		int a,b;
		scanf("%d%d",&a,&b);a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	memset(f,-1,sizeof(f));f[0]=0;
	dfs(0);dfs2(0);
	for(int i=0;i<n;++i){
//		printf(" %d %d %d\n",i+1,nv[i],pv[i]);
	}
	f[0]=-1;
	prepr();
	while(m--){
		int u,v;
		scanf("%d%d",&u,&v);u--;v--;
		printf("%.10lf\n",query(u,v));
	}
	return 0;
}