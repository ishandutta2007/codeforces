#include<cstdio>
const int N=1000002;
int n,x,y,a[N],i;
bool Pre(int i){
	for(int j=i-x;j<i;j++)
		if(j>=1&&j<=n&&a[j]<=a[i])
			return 0;
	return 1;
}
bool Nxt(int i){
	for(int j=i+1;j<=i+y;j++)
		if(j>=1&&j<=n&&a[j]<=a[i])
			return 0;
	return 1;
}
int main(){
	scanf("%d%d%d",&n,&x,&y);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(i=1;i<=n;i++)
		if(Pre(i)&&Nxt(i)){
			printf("%d",i);
			return 0;
		}
}