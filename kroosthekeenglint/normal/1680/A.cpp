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
        int i;
        for (i=1;i<=50;i++)
        {
            if ((a<=i)&&(i<=b)&&(c<=i)&&(i<=d))
            {
                break;
            }
        }
        if (i==51)
        {
            printf("%d\n",a+c);
        }
        else
        {
            printf("%d\n",min(i,a+c));
        }
    }
    return 0;
}