#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
LL k,a,b,A,B;
int main()
{
    scanf("%I64d%I64d%I64d",&k,&a,&b);
    A=(a%k+k)%k;
    if(A==0) A+=k;
    B=b+A-a;
    printf("%I64d\n",B/k-(A-1)/k);
    return 0;
}