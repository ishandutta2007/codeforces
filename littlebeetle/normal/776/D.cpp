#include<cstdio>
const int N=200002;
int n,m,i,x,y,t[N],g[N][2],f[N];
int p(int x){
	return x==f[x]?x:f[x]=p(f[x]);
}
void merge(int x,int y){
	x=p(x);y=p(y);
	if(x!=y)
		f[x]=y;
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",t+i);
	for(i=1;i<=m;i++){
		f[i]=i;
		f[i+m]=i+m;
		scanf("%d",&x);
		while(x--){
			scanf("%d",&y);
			if(g[y][0])
				g[y][1]=i;
			else
				g[y][0]=i;
		}
	}
	for(i=1;i<=n;i++){
		if(t[i]==0)
			merge(g[i][0],g[i][1]+m),
			merge(g[i][0]+m,g[i][1]);
		else
			merge(g[i][0],g[i][1]),
			merge(g[i][0]+m,g[i][1]+m);
	}
	for(i=1;i<=m;i++)
		if(p(i)==p(i+m)){
			printf("NO");
			return 0;
		}
	printf("YES");
	return 0;
}