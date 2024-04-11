#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
using namespace std;

int main()
{
    int n,m,a;
    scanf("%d%d%d",&n,&m,&a);
    printf("%lld",(((long long)(n+a-1)/a))*((long long)(m+a-1)/a));
    return 0;
}