#include<cstdio>
const int N=1000002;
int n,i,j,k,a,b,h[N],t[N],v[N],dep[N];
double p;
void dfs(int i,int fa){
	p+=1.0/dep[i];
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa)
			dep[v[j]]=dep[i]+1,
			dfs(v[j],i);
}
int main(){
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		t[++k]=h[a];h[a]=k;v[k]=b;
		t[++k]=h[b];h[b]=k;v[k]=a;
	}
	dep[1]=1;
	dfs(1,0);
	printf("%.10lf",p);
}