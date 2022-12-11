#include<cstdio>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

int p[200001],u[300001],v[300001],pp[200001];
multiset<int>s[200001];
vector<int>g[500001];
int op1[500001],op2[500001];
int f[200001],sz[200001],fr[300001],vis[300001];
int ff(int u){
	return f[u]==u?u:f[u]=ff(f[u]);
}
int RAND(){
	return abs(rand()*32768+rand());
}
int main(){
	int n,m,k;
	/*	n=200000;
		m=300000;
		k=500000;*/
	scanf("%d%d%d",&n,&m,&k);
	/*	for(int i=1;i<=n;i++)
			p[i]=i;
		random_shuffle(p+1,p+n+1);
	*/
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		pp[p[i]]=i;
	}
	for(int i=1;i<=m;i++){
		//	u[i]=RAND()%n+1,v[i]=RAND()%n+1;
		//	while(u[i]==v[i])
		//		u[i]=RAND()%n+1,v[i]=RAND()%n+1;
		scanf("%d%d",&u[i],&v[i]);
	}
	for(int i=1;i<=k;i++){
		scanf("%d%d",&op1[i],&op2[i]);
		//	op1[i]=rand()%2;
		//	op2[i]=RAND()%(op1[i]==1?n:m)+1;
		if(op1[i]==2)vis[op2[i]]=1;
	}
	for(int i=1;i<=n;i++){
		f[i]=i;
		g[i].push_back(i);
		sz[i]=1;
	}
	for(int i=1;i<=m;i++)
		if(!vis[i]){
			if(ff(u[i])==ff(v[i]))continue;
			if(sz[ff(u[i])]>sz[ff(v[i])])
				swap(u[i],v[i]);
			for(int j=0;j<g[ff(u[i])].size();j++){
				g[ff(v[i])].push_back(g[ff(u[i])][j]);
			}
			sz[ff(v[i])]+=sz[ff(u[i])];
			f[ff(u[i])]=ff(v[i]);
		}
	for(int ii=k;ii;ii--)
		if(op1[ii]==2){
			int i=op2[ii];
			if(ff(u[i])==ff(v[i]))continue;
			if(sz[ff(u[i])]>sz[ff(v[i])])
				swap(u[i],v[i]);
			for(int j=0;j<g[ff(u[i])].size();j++){
				g[ff(v[i])].push_back(g[ff(u[i])][j]);
				g[n+i].push_back(g[ff(u[i])][j]);
			}
			fr[i]=ff(u[i]);
			sz[ff(v[i])]+=sz[ff(u[i])];
			f[ff(u[i])]=ff(v[i]);
		}
	for(int i=1;i<=n;i++)
		s[ff(i)].insert(p[i]);
	for(int i=1;i<=k;i++){
		if(op1[i]==1){
			int ii=op2[i];
			int w=*--s[ff(ii)].end();
			s[ff(ii)].erase(--s[ff(ii)].end());
			printf("%d\n",w);
			p[pp[w]]=0;
			s[ff(ii)].insert(0);
		}
		else{
			int ii=op2[i],rr=fr[ii];
			for(int j=0;j<g[ii+n].size();j++)
				s[ff(rr)].erase(s[ff(rr)].find(p[g[ii+n][j]]));
			for(int j=0;j<g[ii+n].size();j++){
				s[rr].insert(p[g[ii+n][j]]);
				f[g[ii+n][j]]=rr;
			}
		}
	}
}