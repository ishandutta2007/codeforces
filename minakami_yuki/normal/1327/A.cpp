#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;

const int N=1e6+10;
LL n,k;

int main()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		scanf("%I64d%I64d",&n,&k);
		if((n&1)^(k&1)) printf("NO\n");
		else if(k*k>n) printf("NO\n");
		else printf("YES\n");
	} 
	return 0;
}