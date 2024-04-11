#include<cstdio>
const int N=100002;
int T,n,i,j,x,p[N],g[N];
void init(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",p+i);
	p[n+1]=N;
	g[n+1]=n+1;
	for(i=n;i;i--){
		g[i]=g[i+1];
		if(p[i]<p[g[i]])
			g[i]=i;
	}
}
void work(){
	for(i=1;i<n;)
		if(g[i]==i)
			i++;
		else{
			x=p[g[i]];
			for(j=g[i];j>i;j--)
				p[j]=p[j-1];
			p[i]=x;
			i=g[i];
			g[i]=g[i+1];
		if(p[i]<p[g[i]])
			g[i]=i;
		}
	for(i=1;i<=n;i++)
		printf("%d ",p[i]);
	printf("\n");
}
int main(){
	scanf("%d",&T);
	while(T--){
		init();
		work();
	}
	//while(1);
}