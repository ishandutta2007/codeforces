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
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if ((long long)d*a == (long long)b*c)
        {
            puts("0");
        }
        else if ((a==0)||(c==0))
        {
            puts("1");
        }
        else if ((((long long)d*a) % ((long long)b*c)) == 0)
        {
            puts("1");
        }
        else if ((((long long)b*c) % ((long long)d*a)) == 0)
        {
            puts("1");
        }
        else
        {
            puts("2");
        }
    }
    return 0;
}