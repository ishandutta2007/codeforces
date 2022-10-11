#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    long long ans=0;
    for (int i=0;i<n;i++)
    {
    	long long a;
    	scanf("%I64d",&a);
    	ans+=a*(min(n-k,i)-max(i-k+1,0)+1);
	}
	printf("%.9lf",(double)ans/(n-k+1));
}