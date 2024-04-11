#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
LL n,k=1;
int main()
{
	scanf("%I64d",&n);
	while(n%k==0) k*=3;
	printf("%I64d\n",n/k+1);
	return 0;
}