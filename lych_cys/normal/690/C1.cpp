#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[100005],b[100005],fa[100005];
int getfa(int x){return x==fa[x]?x:fa[x]=getfa(fa[x]); }
int calc(int x){
	int i,t=n;for(i=1;i<=n;i++)fa[i]=i;
		for (i=1; i<=m; i++) if (i!=x){
		int u=getfa(a[i]),v=getfa(b[i]);
		if (u!=v){ fa[u]=v;	t--;}
		}return t;
}
int main(){
	scanf("%d%d",&n,&m); int i;
	for (i=1; i<=m; i++) scanf("%d%d",&a[i],&b[i]);
	if (calc(0)>1){ puts("no"); return 0; }
	for (i=1; i<=m; i++) if (calc(i)==1){ puts("no"); return 0; }puts("yes");
	return 0;
}