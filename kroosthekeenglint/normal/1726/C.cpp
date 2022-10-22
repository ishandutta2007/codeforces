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
char a[200005];
vector<int> v[200005];
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
        scanf("%s",a);
        int i;
        int sum = 0;
        for (i=0;i<n+n;i++)
        {
            if (a[i] == '(')
            {
                sum ++;
            }
            else
            {
                sum --;
                v[sum].push_back(i);
            }
        }
        int ans = 0;
        vector<int> t;
        t.push_back(n+n);
        for (i=0;i<n;i++)
        {
            int j;
            int k = 0;
            int flag = 0;
            for (j=0;j<v[i].size();)
            {
                if (v[i][j] < t[k])
                {
                    flag = 1;
                    j++;
                }
                else
                {
                    ans += flag;
                    flag = 0;
                    k++;
                }
            }
            ans += flag;
            t = v[i];
            v[i].clear();
        }
        printf("%d\n",ans);
    }
    return 0;
}