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
        int min_val=1000000007;
        int min_i=-1;
        for (i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            if (x<min_val)
            {
                min_val=x;
                min_i=i;
            }
        }
        if ((n%2==1)||(min_i%2==1))
        {
            puts("Mike");
        }
        else
        {
            puts("Joe");
        }
    }
    return 0;
}