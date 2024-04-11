#include<cstdio>
int n,a,x,b,y;
int main(){
	scanf("%d%d%d%d%d",&n,&a,&x,&b,&y);

	while(1){
		if(a==b){
			printf("YES");
			return 0;
		}
		if(a==x||b==y){
			printf("NO");
			return 0;
		}
		a++;
		if(a>n)
		a=1;
		b--;
		if(b<1)
		b=n;
	}
}