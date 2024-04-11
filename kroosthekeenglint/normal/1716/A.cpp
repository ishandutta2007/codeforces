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
        if (n==1)
        {
            printf("2\n");
        }
        else if (n%3==0)
        {
            printf("%d\n",n/3);
        }
        else if (n%3==1)
        {
            printf("%d\n",n/3+1); 
        }
        else if (n%3==2)
        {
            printf("%d\n",n/3+1); 
        }
    }
    return 0;
}