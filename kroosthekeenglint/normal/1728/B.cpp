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
        if (n == 4)
        {
            printf("2 1 3 4\n");
            continue;
        }
        int i;
        int cnt = 0;
        for (i=4;i<=n-2;i++)
        {
            printf("%d ",i);
            if (cnt < i)
            {
                cnt+=i;
            }
            else
            {
                cnt = 0;
            } 
        }
        printf("1 3 2 %d %d\n",n-1,n);
    }
    return 0;
}