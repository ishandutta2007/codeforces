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
int row[1000005],column[1000005];
char a[1000005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t;
    scanf("%d",&t);
    int n,m;
    int zu;
    for (zu=0;zu<t;zu++)
    {
        scanf("%d%d",&n,&m);
        int i;
        for (i=0;i<n*m;i++)
        {
            row[i]=0;
            column[i]=0;
        }
        scanf("%s",a);
        int ans=0;
        int cnt=0;
        for (i=0;i<n*m;i++)
        {
            if (a[i]=='1')
            {
                if (column[i%m]==0)
                {
                    column[i%m]=1;
                    ans++;
                }
            }
            cnt += (a[i]-'0');
            if (i>=m)
            {
                cnt -= (a[i-m]-'0');
            }
            if (cnt>0)
            {
                row[i%m]++;
            }
            printf("%d ",row[i%m]+ans);
        }
        printf("\n");
    }
    return 0;
}