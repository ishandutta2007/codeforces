#include <cstdio>

int main(){
	int a,b,c,x,y,z;
	scanf("%d %d %d",&a,&b,&c);
	x=(b+a-c)/2;
	y=(b+c-a)/2;
	z=(a+c-b)/2;
	if(x+z==a&&x+y==b&&y+z==c&&x>=0&&y>=0&&z>=0){
		printf("%d %d %d\n",x,y,z);
	}
	else puts("Impossible");
	return 0;
}