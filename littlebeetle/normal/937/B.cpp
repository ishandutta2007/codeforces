#include<cstdio>
int p,y,i;
bool ok(int x){
	if(x<=p)
		return 0;
	for(int k=2;k*k<=x;k++)
		if(x%k==0&&k<=p)
			return 0;
	return 1;
}
int main(){
	scanf("%d%d",&p,&y);
	for(i=y;i>=2&&y-i<=1000;i--)
		if(ok(i)){
			printf("%d\n",i);
			return 0;
		}
	printf("-1");
	//	while(1);
}