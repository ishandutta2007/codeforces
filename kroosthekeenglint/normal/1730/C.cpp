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
char a[200005];
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
        scanf("%s",a);
        int n = strlen(a);
        int i;
        char min_val = 'a';
        for (i=n-1;i>=0;i--)
        {
            min_val = min(min_val, a[i]);
            if (a[i] != min_val)
            {
                if (a[i] != '9')
                {
                    a[i]++;
                }
            }
        }
        sort(a,a+n);
        printf("%s\n",a);
    }
    return 0;
}