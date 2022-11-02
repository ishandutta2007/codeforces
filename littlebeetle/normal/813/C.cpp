#include<cstdio>
const int N=400020;
int n,x,i,j,k,a,b,h[N],t[N],v[N],d[N],D[N],f[N],s,p;
void dfs(int i,int fa){
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa){
			f[v[j]]=i;
			D[v[j]]=d[v[j]]=d[i]+1;
			dfs(v[j],i);
			if(D[v[j]]>D[i])
				D[i]=D[v[j]];
		}
}
int main(){
	scanf("%d%d",&n,&x);
	for(i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		t[++k]=h[a];h[a]=k;v[k]=b;
		t[++k]=h[b];h[b]=k;v[k]=a;
	}
	dfs(1,0);
	p=(d[x]-1)/2;
	while(p--)
		x=f[x];
	printf("%d",D[x]*2);
}