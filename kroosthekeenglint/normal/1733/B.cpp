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
        int n,x,y;
        scanf("%d%d%d",&n,&x,&y);
        if (x>y)
        {
            swap(x,y);
        }
        n--;
        if ((x!=0)||(y==0))
        {
            puts("-1");
            continue;
        }
        if (n%y != 0)
        {
            puts("-1");
            continue;
        }
        int i;
        for (i=0;i<n/y;i++)
        {
            int j;
            for (j=0;j<y;j++)
            {
                printf("%d ",i*y+2);
            }
        }
        printf("\n");
    } 
    return 0;
}