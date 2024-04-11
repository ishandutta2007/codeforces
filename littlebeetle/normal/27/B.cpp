#include<cstdio>
const int N=54;
int n,i,a,b,f[N][N],g[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<n*(n-1)/2;i++){
		scanf("%d%d",&a,&b);
		f[a][b]=1;
		f[b][a]=1;
		g[a]++;
	}
	for(a=1;a<=n;a++)
		for(b=1;b<=n;b++)
			if(a!=b&&!f[a][b]&&g[a]>=g[b]){
				printf("%d %d",a,b);
				//while(1);
					return 0;
				}
}