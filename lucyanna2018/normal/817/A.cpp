#include<stdio.h>
#include<stdlib.h>
bool dv(int x,int y){
	return x%y==0;
}
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int main(){
	int x1,y1,x2,y2,x,y;
	scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x,&y);
	puts(dv(x2-x1,x) && dv(y2-y1,y) && labs((x2-x1)/x%2) == labs((y2-y1)/y%2)? "YES" : "NO");
	return 0;
}