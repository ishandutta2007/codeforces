#include<cstdio>
const int N=5002;
int n,m,a,c[N],g[N],f[N],i,j,l;
int min(int x,int y){
	return x<y?x:y;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		if(a!=c[m])
			c[++m]=a;
	}
	for(l=1;l<m;l++)
		for(i=1;i+l<=m;i++){
			g[i]=f[i];
			if(c[i]==c[i+l])
				f[i]=g[i+1]+1;
			else
				f[i]=min(f[i+1],f[i])+1;
		}
	printf("%d",f[1]);
}