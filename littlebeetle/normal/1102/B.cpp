#include<cstdio>
const int N=5002;
bool f[N][N];
int n,k,a,c[N],i,j,p=1;
int main(){
	scanf("%d%d",&n,&k);
	for(i=p=1;i<=n;i++){
		scanf("%d",&a);
		if(p<=k){
			c[i]=p;
			f[a][p++]=1;
		}
		else{
			for(j=1;j<=k;j++)
				if(!f[a][j])
					break;
			if(j>k){
				printf("NO");
				return 0;
			}
			f[a][j]=1;
			c[i]=j;
		}
	}
	printf("YES\n");
	for(i=1;i<=n;i++)
		printf("%d ",c[i]);
	return 0;
}