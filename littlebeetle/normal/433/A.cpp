#include<cstdio>
int n,i,a,b,x;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&x);
		if(x==100)
		a++;
		else
		b++;
	}
	if(a%2==1||(a==0&&b%2==1))
		printf("NO");
	else
		printf("YES");
}