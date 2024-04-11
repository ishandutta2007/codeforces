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
int cur_p[100005];
int a[100005];
int ans[100005];
vector<int> v[100005];
const int sqrtn = 320;
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
        int n,k;
        scanf("%d%d",&n,&k);
        int i;
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for (i=0;i<n;i++)
        {
            cur_p[i] = 1;
            v[a[i]].push_back(i);
        }
        int min_ans = 1000005;
        int min_val = a[0];
        for (i=100000;i>=a[n-1]/k;i--)
        {
            min_ans=min(min_ans,i-min_val);
            int j;
            for (j=0;j<v[i].size();j++)
            {
                int x = v[i][j];
                cur_p[x]++;
                int t = cur_p[x];
                if (a[x]/t == i)
                {
                    if (i==0)
                    {
                        continue;
                    }
                    t = a[x]/i + 1;
                    cur_p[x] = t-1;
                    if (t>k)
                    {
                        continue;
                    }
                }
                v[a[x]/t].push_back(x);
                min_val = min(min_val, a[x]/t);
            }
            v[i].clear();
        }
        for (;i>=0;i--)
        {
            v[i].clear();
        }
        printf("%d\n",min_ans);
    }
    return 0;
}