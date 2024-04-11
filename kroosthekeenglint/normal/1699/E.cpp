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
int dp[5000005];
bool vis[5000005];
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
        int n,m;
        scanf("%d%d",&n,&m);
        int i;
        for (i=0;i<=m;i++)
        {
            dp[i]=-m;
            vis[i]=0;
        }
        for (i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            vis[x]=1;
        }
        dp[1]=1;
        multiset<int> ans;
        for (i=1;i<=m;i++)
        {
            if (vis[i])
            {
                ans.insert(dp[i]);
            }
        }
        int min_ans = m+m;
        multiset<int>::iterator ii = ans.begin();
        min_ans=min(min_ans,1-(*ii));
        for (i=2;i<=m;i++)
        {
            int j;
            if (vis[i])
            {
                ans.erase(ans.find(dp[i]));
            }
            dp[i]=i;
            if (vis[i])
            {
                ans.insert(dp[i]);
            }
            for (j=i+i;j<=m;j+=i)
            {
                if (dp[j/i]>dp[j])
                {
                    if (vis[j])
                    {
                        ans.erase(ans.find(dp[j]));
                    }
                    dp[j]=dp[j/i];
                    if (vis[j])
                    {
                        ans.insert(dp[j]);
                    }
                }
            }
            multiset<int>::iterator ii = ans.begin();
            min_ans=min(min_ans,i-(*ii));
        }
        printf("%d\n",min_ans);
    } 
    return 0;
}