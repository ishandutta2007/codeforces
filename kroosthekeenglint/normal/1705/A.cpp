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
int a[100005];
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
        int n,s;
        scanf("%d%d",&n,&s);
        int i;
        for (i=0;i<2*n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n+n);
        for (i=0;i<n;i++)
        {
            if (a[i+n]-a[i]<s)
            {
                puts("NO");
                break;
            }
        }
        if (i==n)
        {
            puts("YES");
        }
    } 
    return 0;
}