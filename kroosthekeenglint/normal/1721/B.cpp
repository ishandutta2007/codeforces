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
        int n,m,x,y,d;
        scanf("%d%d%d%d%d",&n,&m,&x,&y,&d);
        if ((x-d <= 1) && (x+d >= n))
        {
            puts("-1");
            continue;
        }
        if ((y-d <= 1) && (y+d >= m))
        {
            puts("-1");
            continue;
        }
        if ((x-d <= 1) && (y-d <= 1))
        {
            puts("-1");
            continue;
        }
        if ((x+d >= n) && (y+d >= m))
        {
            puts("-1");
            continue;
        }
        printf("%d\n",n+m-2);
    }
    return 0;
}