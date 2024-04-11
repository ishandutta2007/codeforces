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
int can_remove[5005][5005];
int num[5005];
int dp[5005];
int a[5005];
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
        int n;
        scanf("%d",&n);
        int i;
        for (i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for (i=0;i<=n+1;i++)
        {
            can_remove[0][i]=n+2;
            can_remove[i][n+2]=n+2;
        }
        for (i=1;i<=n;i++)
        {
            int j;
            for (j=1;j<=n;j++)
            {
                num[j]=0;
            }
            int over_max_num = -1; 
            int sum_num = 0;
            for (j=i;j<=n;j++)
            {
                sum_num++;
                num[a[j]]++;
                if (num[a[j]] * 2 > sum_num)
                {
                    over_max_num = a[j];
                }
                if (num[over_max_num] * 2 <= sum_num)
                {
                    over_max_num = -1;
                }
                if (over_max_num == -1)
                {
                    can_remove[i][j+1]=0;
                }
                else
                {
                    can_remove[i][j+1]=num[over_max_num] * 2 - sum_num;
                }
            }
        }
        int max_ans = 0;
        for (i=1;i<=n;i++)
        {
            int j;
            vector<int> v;
            v.push_back(0);
            a[0]=i;
            a[n+1]=i;
            dp[0]=-1;
            for (j=1;j<=n+1;j++)
            {
                if (a[j]==i)
                {
                    dp[j] = -(n+2);
                    int k;
                    for (k=0;k<(int)v.size();k++)
                    {
                        int num = v[k];
                        if ((j-num)%2!=1)
                        {
                            continue;
                        }
                        dp[j] = max(dp[j], dp[v[k]]+1-can_remove[v[k]+1][j]);
                    }
                    v.push_back(j);
                }
            }
            max_ans=max(max_ans,dp[n+1]); 
        }
        printf("%d\n",max_ans);
    }
    return 0;
}