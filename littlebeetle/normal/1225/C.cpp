#include<cstdio>
int n,p,k;
int bit(int x){
	if(x==0)return 0;
	return bit(x-(x&-x))+1;
}
bool check(int n,int k){
	if(n<0)return 0;
	if(bit(n)<=k&&k<=n)
		return 1;
	return 0;
}
int main(){
	scanf("%d%d",&n,&p);
	for(k=1;k<=1000;k++)
		if(check(n-k*p,k)){
			printf("%d",k);
			//while(1);
			return 0;
		}
	printf("-1");
	return 0;
}