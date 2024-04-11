#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a,b,c,x;
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	if((a+b+c)&1) {puts("Impossible");return 0;}
	x=(a+b+c)>>1;
	int A=x-c,B=x-a,C=x-b;
	if(max(max(a,b),c)>x) {puts("Impossible");return 0;}
	if(A+B==0||B+C==0||C+A==0) {puts("Impossible");return 0;}
	printf("%d %d %d\n",A,B,C);
	return 0;
}