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
vector<int> v;
bool check(int x)
{
    static int c[15];
    int cnt=0;
    for (;x!=0;x/=10)
    {
        c[cnt++]=x%10;
    }
    int i;
    for (i=0;i<cnt;i++)
    {
        if (c[i]!=c[cnt-i-1])
        {
            return false;
        }
    }
    return true;
}
int dp[40005][505];
const int modo=1000000007;
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int i;
    for (i=1;i<=40000;i++)
    {
        if (check(i))
        {
            v.push_back(i);
        }
    }
    dp[0][0]=1;
    for (i=0;i<=40000;i++)
    {
        int j;
        for (j=0;j<v.size();j++)
        {
            if (i>=v[j])
            {
                dp[i][j]=(dp[i][j]+dp[i-v[j]][j])%modo;
            }
            if (j>0)
            {
                dp[i][j]=(dp[i][j]+dp[i][j-1])%modo;
            }
        }
    }
    int t;
    scanf("%d",&t);
    int zu;
    for (zu=0;zu<t;zu++)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",dp[n][v.size()-1]);
    }
    return 0;
}