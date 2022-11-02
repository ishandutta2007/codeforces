#include<cstdio>
const int N=1002;
int n,a,b,k,i,j,p[N][N],opt;
int main(){
	scanf("%d%d%d",&n,&a,&b);
	if(n==1&&a==1&&b==1){
		printf("YES\n0");
		return 0;
	}
	if(n<4&&a==1&&b==1){
		printf("NO");
		return 0;
	}
	if(a>1&&b>1){
		printf("NO");
		return 0;
	}
	if(b==1){
		opt=1;
		k=a;a=b;b=k;
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i!=j)
				p[i][j]=1;
	b=n-b;
	for(i=1;i<=b;i++)
		p[i][i+1]=p[i+1][i]=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i!=j)
				p[i][j]^=opt;
	printf("YES\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
			printf("%d",p[i][j]);
		printf("\n");
	}
	//while(1);
}