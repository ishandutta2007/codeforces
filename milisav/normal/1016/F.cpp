#include<bits/stdc++.h>
using namespace std;
long long d[300005];
long long b[300005];
long long ld[300005];
int c[300005];
int n;
int m;
vector<pair<int,long long> > a[300005];
bool p[300005];
bool k=false;
long long g,h;
bool dfs(int u)
{
	p[u]=false;
	if(u==n-1) p[u]=true;
	int v;
	for(int i=0;i<a[u].size();i++) {
		v=a[u][i].first;
		if(d[v]==-1) {
			d[v]=d[u]+a[u][i].second;
			dfs(v);
			if(p[v]) p[u]=true;
		}
	}
	return p[u];
}
bool dfs1(int u)
{
	int v;
	c[u]=1;
	for(int i=0;i<a[u].size();i++) {
		v=a[u][i].first;
		if(b[v]==-1 && !p[v]) {
			b[v]=b[u]+a[u][i].second;
			if(dfs1(v)) k=true;
			ld[u]=max(ld[u],ld[v]+a[u][i].second);
			c[u]+=c[v];
		}
	}
	if(c[u]>=3) return true;
	else return false;
}
void spfs(int u,long long w1,long long w2)
{
	//cout<<u<<" "<<w<<" "<<ld[u]<<endl;
	if(w1!=-1 && ld[u]!=0) h=max(h,w1+d[n-1]-d[u]+ld[u]);
	if(w2!=-1) h=max(h,w2+d[n-1]-d[u]+ld[u]);
	if(u==n-1) return;
	int v;
	for(int i=0;i<a[u].size();i++) {
		v=a[u][i].first;
		if(d[v]==d[u]+a[u][i].second && p[v]) {
			spfs(v,max(w1,d[u]+ld[u]),ld[u]==0 ? max(w2,w1) : max(w2,d[u]+ld[u]));
		}
	}
}
int main()
{
	int u,v,w;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n-1;i++) {
		scanf("%d %d %d",&u,&v,&w);
		u--;
		v--;
		a[u].push_back(make_pair(v,w));
		a[v].push_back(make_pair(u,w));
	}
	for(int i=0;i<n;i++) {
		d[i]=-1;
		b[i]=-1;
	}
	d[0]=0;
	if(!dfs(0)) {
		printf("NOOOOOOO");
		return 0;
	}
	g=d[n-1];
	for(int i=0;i<n;i++) {
		if(p[i]) {
			b[i]=0;
			if(dfs1(i)) k=true;
		}
	}
	spfs(0,-1,-1);
	//cout<<g<<" "<<h<<endl;
	for(int i=0;i<m;i++) {
		scanf("%d",&w);
		if(k) printf("%lld\n",g);
		else printf("%lld\n",min(g,h+w));
	}
	return 0;
}