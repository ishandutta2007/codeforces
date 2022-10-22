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
int a[105],b[105];
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
        int ans1=0,ans2=1;
        int cnt = 0;
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if (a[i] == 1)
            {
                cnt++;
            }
        }
        for (i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
            if (b[i] == 1)
            {
                cnt --;
            }
            if (a[i] != b[i])
            {
                ans1++;
            }
        }
        ans2 += abs(cnt);
        printf("%d\n",min(ans1,ans2));
    }
    return 0;
}