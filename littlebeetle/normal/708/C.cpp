#include<cstdio>
const int N=800020;
int n,i,j,k,a,b,h[N],t[N],v[N],s[N],g[N],G[N],p[N],e[N];
bool f[N];
int max(int x,int y){
	return x>y?x:y;
}
void dfs(int i,int fa){
	s[i]=1;
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa){
			dfs(v[j],i);
			s[i]+=s[v[j]];
			if(s[v[j]]>e[i])
				e[i]=s[v[j]];
			if(s[v[j]]<=n/2)
				g[i]=max(g[i],s[v[j]]);
			else
				if(g[v[j]]<=n/2)
					g[i]=max(g[i],g[v[j]]);
		}
	if(s[i]<=n/2)
		G[i]=s[i];
	else
		G[i]=g[i];
}
void dfs2(int i,int fa){
	if(max(max(g[i],e[i]-g[i]),max(n-s[i]-p[i],p[i]))<=n/2)
		f[i]=1;
	int x=0,y=0;
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa){
			if(G[v[j]]>=x)
				y=x,x=G[v[j]];
			else if(G[v[j]]>y)
				y=G[v[j]];
		}
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa){
			if(n-s[v[j]]<=n/2)
				p[v[j]]=n-s[v[j]];
			else{
				if(G[v[j]]==x)
					p[v[j]]=max(y,p[i]);
				else
					p[v[j]]=max(x,p[i]);
			}
			dfs2(v[j],i);
		}
}
int main(){
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		t[++k]=h[a];h[a]=k;v[k]=b;
		t[++k]=h[b];h[b]=k;v[k]=a;
	}
	dfs(1,0);
	dfs2(1,0);
	for(i=1;i<=n;i++)
		printf("%d ",f[i]);
	//while(1);
}