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
int a[5];
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
        int x;
        scanf("%d",&x);
        scanf("%d%d%d",&a[1],&a[2],&a[3]);
        int i;
        for (i=0;i<3;i++)
        {
            x=a[x];
            if (x==0)
            {
                break;
            }
        }
        if (i==2)
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