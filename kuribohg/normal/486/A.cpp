#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
typedef long long LL;
LL n;
int main()
{
    scanf("%I64d",&n);
    if(n&1) putchar('-');
    printf("%I64d\n",(LL)(n+1)>>1);
    return 0;
}