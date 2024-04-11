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
int a[105];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int zu;
    scanf("%d",&zu);
    int t;
    for (t=0;t<zu;t++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int i;
        for (i=0;i<m;i++)
        {
            a[i] = 0;
        }
        for (i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            a[i%m] = max(a[i%m],x);
        }
        long long sum = 0;
        for (i=0;i<m;i++)
        {
            sum += a[i];
        }
        printf("%lld\n",sum);
    } 
    return 0;
}