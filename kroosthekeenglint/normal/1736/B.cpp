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
int gcd(int x,int y)
{
    if (y == 0)
    {
        return x;
    }
    return gcd(y,x%y);
}
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
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]); 
        }
        for (i=1;i<n-1;i++)
        {
            if (a[i]%gcd(a[i-1],a[i+1])!=0)
            {
                puts("NO");
                break;
            }
        }
        if (i>=n-1)
        {
            puts("YES");
        }
    }
    return 0;
}