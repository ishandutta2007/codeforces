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
int a[100005];
int ans[100005];
int num[100005];
vector<int> v[100005];
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
        int cnt = 0;
        for (i=0;i<=n+1;i++)
        {
            num[i] = 0;
            v[i].clear();
        } 
        for (i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            num[a[i]]++;
            if (a[i]>=i)
            {
                cnt++;
            }
        }
        printf("%d\n",cnt);
        for (i=1;i<=n;i++)
        {
            if (num[i] == 0)
            {
                v[a[i]].push_back(i);
            }
        }
        for (i=1;i<=n;i++)
        {
            if (num[i] != 0)
            {
                v[a[i]].push_back(i);
            }
        }
        int s = 0;
        if (v[0].size() == 0)
        {
            s = n+1;
        }
        for (;;)
        {
            int i;
            for (i=0;i<v[s].size();i++)
            {
                printf("%d ",v[s][i]);
            }
            s = v[s][v[s].size()-1];
            if (num[s] == 0)
            {
                printf("\n");
                break;
            }
        }
    }
    return 0;
}