#include<cstdio>
int n,k;
int min(int x,int y){
	return x<y?x:y;
}
int main(){
	scanf("%d%d",&n,&k);
	if(k==0||k==n)
		printf("0");
	else
		printf("1");
	printf(" %d",min(k*2,n-k));
}