#include<cstdio>
const int N=102;
int n,m,i,j,X,a[N][N],b[N][N],k;
int Ans,ans,opt;
int min(int x,int y){
	return x<y?x:y;
}
void init(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",a[i]+j);
	X=1<<30;
	for(j=1;j<=m;j++)
		X=min(a[1][j],X);
}
int check(int x){
	int sum=x;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			b[i][j]=a[i][j];
	for(j=1;j<=m;j++)
		b[1][j]-=x,sum+=b[1][j];
	for(i=n;i;i--)
		for(j=1;j<=m;j++){
			b[i][j]-=b[1][j];
			if(b[i][j]<0)
				return -1;
		}
	for(i=2;i<=n;i++){
		sum+=b[i][1];
		for(j=2;j<=m;j++)
			if(b[i][j]!=b[i][j-1])
				return -1;
	}
	return sum;
}
void Out(int x){
	int sum=x;
	for(k=0;k<x;k++)
		printf("row %d\n",1);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			b[i][j]=a[i][j];
	for(j=1;j<=m;j++){
		b[1][j]-=x;
		for(k=0;k<b[1][j];k++)
			printf("col %d\n",j);
	}
	for(i=n;i;i--)
		for(j=1;j<=m;j++)
			b[i][j]-=b[1][j];
	for(i=2;i<=n;i++){
		for(k=0;k<b[i][1];k++)
			printf("row %d\n",i);
		sum+=b[i][1];
	}
}
void work(){
	Ans=1<<30;
	while(X>=0){
		ans=check(X);
		if(ans!=-1){
			if(ans<Ans){
				Ans=ans;
				opt=X;
			}
		}
		X--;
	}
	if(Ans==1<<30)
		printf("-1");
	else{
		printf("%d\n",Ans);
		Out(opt);
	}
	//while(1);
}
int main(){
	init();
	work();
	return 0;
}