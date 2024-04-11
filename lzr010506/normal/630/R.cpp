#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<queue>
#include<stack>
#define INF 0x3f3f3f
#define MAX 100100
#define LL long long
using namespace std;
int main()
{
    LL n,m,j,i;
    while(scanf("%I64d",&n)!=EOF)
    {
        if(n&1)
            printf("1\n");
        else
            printf("2\n");
    }
    return 0;
}