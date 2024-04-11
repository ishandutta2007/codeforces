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
        int n,k,r,c;
        scanf("%d%d%d%d",&n,&k,&r,&c);
        int i,j;
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                if ((j-i+r-c)%k==0)
                {
                    printf("X");
                }
                else
                {
                    printf(".");
                }
            }
            printf("\n");
        }
    }
    return 0;
}