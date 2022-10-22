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
        printf("2\n");
        for (i=1;i<=n;i+=2)
        {
            printf("%d ",i);
            int now = i;
            for (;;)
            {
                now<<=1;
                if (now > n)
                {
                    break;
                }
                printf("%d ",now);
            }
        }
        printf("\n"); 
    } 
    return 0;
}