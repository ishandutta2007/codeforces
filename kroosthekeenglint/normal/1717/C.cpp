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
int a[200005];
int b[200005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int zu;
    scanf("%d",&zu);
    int t;
    for (t=0;t<zu;t++)
    {
        int n;
        scanf("%d",&n);
        int i;
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]); 
        }
        a[n]=a[0];
        for (i=0;i<n;i++)
        {
            scanf("%d",&b[i]); 
        }
        b[n]=b[0];
        bool ans = 1;
        for (i=0;i<n;i++)
        {
            if (a[i] == b[i])
            {
                continue;
            }
            if (b[i] - b[i+1] > 1)
            {
                ans = 0;
                break;
            }
            if (a[i] > b[i])
            {
                ans = 0;
                break;
            }
        }
        if (ans)
        {
            puts("YES");
        }
        else
        {
            puts("NO");
        }
    }
    return 0;
}