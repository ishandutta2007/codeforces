#include<cstdio>
#include<cstring>
int n,l,r,Answer;
int main(){
	scanf("%d %d %d",&n,&l,&r);
	Answer=(1<<l)-1;
	Answer+=n-l;
	printf("%d ",Answer);
	Answer=(1<<r)-1;
	Answer+=(n-r)*(1<<r-1);
	printf("%d\n",Answer);
	return 0;
}