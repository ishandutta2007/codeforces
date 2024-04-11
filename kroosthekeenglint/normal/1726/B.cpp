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
        if ((n>m) || ((n%2==0) && (m%2==1)))
        {
            puts("No");
            continue;
        }
        puts("Yes");
        if (n%2 == 0)
        {
            int i;
            for (i=2;i<n;i++)
            {
                printf("1 ");
                m--;
            }
            printf("%d %d\n",m/2,m/2);
        }
        else
        {
            int i;
            for (i=1;i<n;i++)
            {
                printf("1 ");
                m--;
            }
            printf("%d\n",m);
        }
    }
    return 0;
}