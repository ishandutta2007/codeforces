#include<cstdio>
const int N=400002;
int n,i,j,k,a,b,c[N],h[N],t[N],v[N],f[N],cnt,id[N],H[N],T[N],V[N],x,dep[N];
int p(int x){
	return x==f[x]?x:f[x]=p(f[x]);
}
void dfs(int i,int fa){
	for(int j=H[i];j;j=T[j])
		if(V[j]!=fa){
			dep[V[j]]=dep[i]+1;
			dfs(V[j],i);
		}
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",c+i),f[i]=i;
	for(i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		if(c[a]==c[b])
			f[p(a)]=p(b);
		t[++k]=h[a];h[a]=k;v[k]=b;
		t[++k]=h[b];h[b]=k;v[k]=a;
	}
	for(i=1;i<=n;i++)
		if(!id[p(i)])
			id[p(i)]=++cnt;
	k=0;
	for(i=1;i<=n;i++)
		for(j=h[i];j;j=t[j])
			if(c[i]!=c[v[j]]){
				a=id[p(i)];
				b=id[p(v[j])];
				T[++k]=H[a];H[a]=k;V[k]=b;
			}
	dfs(1,0);
	for(i=1;i<=n;i++){
		if(dep[i]>dep[x])
			x=i;
	}
	for(i=1;i<=n;i++)
		dep[i]=0;
	dfs(x,0);
	for(i=1,x=0;i<=n;i++)
		if(dep[i]>x)
			x=dep[i];
	printf("%d",(x+1)/2);
}