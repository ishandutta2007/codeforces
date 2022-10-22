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
int a[100005],b[100005],d[100005];
int anti_a[100005],anti_b[100005];
bool vis[100005];
const int modo=1000000007;
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
            anti_a[i]=-1;
            anti_b[i]=-1;
            vis[i]=false;
        }
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            a[i]--;
            anti_a[a[i]]=i;
        }
        for (i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
            b[i]--;
            anti_b[b[i]]=i;
        }
        for (i=0;i<n;i++)
        {
            scanf("%d",&d[i]);
            d[i]--;
        }
        int p=1;
        for (i=0;i<n;i++)
        {
            if (vis[i])
            {
                continue;
            }
            if (a[i]==b[i])
            {
                if ((d[i]==a[i])||(d[i]==-1))
                {
                    continue;
                }
                p=0;
                break;
            }
            int cnt=0;
            int pos=i;
            int res=a[i];
            for (;;)
            {
                if ((d[pos]!=-1)&&(d[pos]!=res))
                {
                    break;
                }
                pos = anti_a[b[pos]];
                res = a[pos];
                if (pos == i)
                {
                    cnt++;
                    break;
                }
            }
            pos=i;
            res=b[i];
            for (;;)
            {
                if ((d[pos]!=-1)&&(d[pos]!=res))
                {
                    break;
                }
                pos = anti_b[a[pos]];
                res = b[pos];
                if (pos == i)
                {
                    cnt++;
                    break;
                }
            }
            p*=cnt;
            if (p>=modo) p-=modo;
            pos=i;
            res=b[i];
            for (;;)
            {
                vis[pos]=true;
                pos = anti_b[a[pos]];
                res = b[pos];
                if (pos == i)
                {
                    cnt++;
                    break;
                }
            }
        }
        printf("%d\n",p);
    }
    return 0;
}