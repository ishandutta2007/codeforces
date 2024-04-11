#include<cstdio>
int n,k,sum,a,x;
int main(){
	scanf("%d%d",&n,&k);
	while(n--){
		scanf("%d",&a);
		sum+=a;
		if(a>x)
			x=a;
	}
	sum-=x;
	if(sum<=k)
		printf("YES");
	else
		printf("NO");
	//while(1);
}