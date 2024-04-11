#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
int n,b,x;
LL A,B;
int main()
{
	scanf("%d%d",&n,&b);
	for(int i=1;i<=n;i++) scanf("%d",&x),A=A*b+x;
	scanf("%d%d",&n,&b);
	for(int i=1;i<=n;i++) scanf("%d",&x),B=B*b+x;
	if(A==B) puts("=");
	else if(A>B) puts(">");
	else puts("<");
	return 0;
}