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
        int n;
        scanf("%d",&n);
        int i;
        int x_max = 0, x_min = 0;
        int y_max = 0, y_min = 0;
        for (i=0;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if (y==0)
            {
                x_max = max(x_max, x);
                x_min = min(x_min, x);
            }
            else if (x==0)
            {
                y_max = max(y_max, y);
                y_min = min(y_min, y);
            }
        }
        printf("%d\n",(x_max-x_min)*2+(y_max-y_min)*2);
    }
    return 0;
}