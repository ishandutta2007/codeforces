#include<cstdio>
#define MAXN 1000
#include<algorithm>
using namespace std;
template<class T>
void Read(T &x){
	char c;
	bool f(0);
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
	}
}
int fa[MAXN+10],size[MAXN+10],n,m,tot,c[MAXN+10],k,mx;
bool vis[MAXN+10];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main()
{
	Read(n),Read(m),Read(k);
	int i,u,v;
	for(i=1;i<=k;i++)
		Read(c[i]);
	for(i=1;i<=n;i++)
		fa[i]=i;
	for(i=1;i<=m;i++){
		Read(u),Read(v);
		if(find(u)!=find(v))
			fa[fa[u]]=fa[v];
	}
	for(i=1;i<=n;i++)
		size[find(i)]++;
	for(i=1;i<=n;i++)
		if(find(i)==i)
			tot+=size[i]*(size[i]-1)/2;
	tot-=m;
	for(i=1;i<=k;i++){
		vis[find(c[i])]=1;
		mx=max(mx,size[find(c[i])]);
	}
	for(i=1;i<=n;i++)
		if(!vis[i]&&find(i)==i){
			tot+=mx*size[i];
			mx+=size[i];
		}
	printf("%d\n",tot);
}