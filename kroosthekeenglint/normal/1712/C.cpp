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
int b[100005];
int c[100005];
set<int> s;
int cnt = 0;
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
            b[i] = 0;
            c[i] = 0;
        }
        s.clear();
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            b[a[i]] = i;
        }
        cnt = 0;
        int last_0 = -1;
        for (i=n-1;i>=0;i--)
        {
            if (c[a[i]] != 1)
            {
                s.insert(a[i]);
                if (s.find(a[i]) != s.begin())
                {
                    c[a[i]] = 1;
                    s.erase(a[i]);
                    s.insert(0);
                    cnt++;
                }
            }
        }
        for (i=0;i<n;i++)
        {
            if ((c[a[i]] == 1) || (i < last_0))
            {
                if (c[a[i]] == 0)
                {
                    c[a[i]] = 1;
                    cnt++;
                }
                last_0 = max(last_0, b[a[i]]);
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}