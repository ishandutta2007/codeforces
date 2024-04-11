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
int s[100005];
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
        for (i=0;i<k;i++)
        {
            scanf("%d",&s[i]);
            if (i == 0)
            {
                int sum = i+n-k+1;
                // s[i] / sum
                int t = s[i] / sum;
                if ((s[i] >= 0) && (s[i] % sum != 0))
                {
                    t++;
                }
                a[i+n-k] = t;
            }
            else
            {
                a[i+n-k] = s[i] - s[i-1];
            }
        }
        for (i=n-k;i<n-1;i++)
        {
            if (a[i] > a[i+1])
            {
                puts("NO");
                break;
            }
        }
        if (i==n-1)
        {
            puts("YES");
        }
    }
    return 0;
}