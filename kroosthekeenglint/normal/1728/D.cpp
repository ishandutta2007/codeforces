#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int dp[2005][2005];
char a[2005];
int calc(char a, char b, int val)
{
    if (val != 0)
    {
        return val;
    }
    return a<b;
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t;
    scanf("%d",&t);
    int zu;
    for (zu=0;zu<t;zu++)
    {
        scanf("%s",a);
        int n = strlen(a);
        int i;
        for (i=0;i<=n;i++)
        {
            dp[i][i] = 0;
        }
        for (i=2;i<=n;i+=2)
        {
            int j;
            for (j=0;i+j<=n;j++)
            {
                int k = i+j;
                dp[j][k] = max(min(calc(a[j], a[k-1], dp[j+1][k-1]), calc(a[j], a[j+1], dp[j+2][k])), min(calc(a[k-1], a[j], dp[j+1][k-1]), calc(a[k-1], a[k-2], dp[j][k-2])));
            }
        }
        if (dp[0][n] == 1)
        {
            puts("Alice");
        }
        else if (dp[0][n] == 0)
        {
            puts("Draw");
        }
        else
        {
            puts("Bob");
            //Is it possible?
        }
    } 
    return 0;
}