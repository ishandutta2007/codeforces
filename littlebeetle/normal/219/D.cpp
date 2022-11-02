#include<cstdio>
const int N=400002;
int n,i,j,k,a,b,c,h[N],t[N],v[N],w[N],p[N];
void dfs(int i,int fa){
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa){
			dfs(v[j],i);
			p[i]+=p[v[j]]+w[j];
		}
}
void dfs2(int i,int fa){
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa){
			p[v[j]]=p[i]+(w[j]?-1:1);
			dfs2(v[j],i);
		}
}
int main(){
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		t[++k]=h[a];h[a]=k;v[k]=b;w[k]=0;
		t[++k]=h[b];h[b]=k;v[k]=a;w[k]=1;
	}
	dfs(1,0);
	dfs2(1,0);
	k=1<<30;
	for(i=1;i<=n;i++)
		if(p[i]<k)
			k=p[i];
	printf("%d\n",k);
	for(i=1;i<=n;i++)
		if(p[i]==k)
			printf("%d ",i);
	return 0;
}