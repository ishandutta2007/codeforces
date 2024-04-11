#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<=n/1234567;i++)
		for(int j=0;j<=(n-i*1234567)/123456;j++)
			if((n-i*1234567-j*123456)%1234==0) {puts("YES");return 0;}
	puts("NO");
	return 0;
}