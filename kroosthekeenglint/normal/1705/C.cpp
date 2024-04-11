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
long long l[200005],r[200005];
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
        int n,c,q;
        scanf("%d%d%d",&n,&c,&q);
        int i;
        scanf("%s",a);
        l[0]=0;
        r[0]=n;
        for (i=1;i<=c;i++)
        {
            scanf("%lld%lld",&l[i],&r[i]);
            l[i]--;
        }
        for (i=0;i<q;i++)
        {
            long long x;
            scanf("%lld",&x);
            x--;
            int j;
            long long len=0;
            for (j=0;j<=c;j++)
            {
                len+=r[j]-l[j];
                if (len>x)
                {
                    break;
                }
            }
            for (;j>=0;j--)
            {
                if (x >= len-(r[j]-l[j]))
                {
                    x = l[j] + (x - (len - (r[j]-l[j])));
                }
                len -= (r[j]-l[j]);
            }
            printf("%c\n",a[x]);
        }
    }
    return 0;
}