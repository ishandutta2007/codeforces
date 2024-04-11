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
int tag[1005][1005];
int anys[1005][1005];
int ans[1<<17][20];
char a[1005];
const int modo=998244353;
int power(int x,int y)
{
    if (y==0)
    {
        return 1;
    }
    int t=power(x,y/2);
    t=(long long)t*t%modo;
    if (y%2==1)
    {
        t=(long long)t*x%modo;
    }
    return t;
}
char b[1005];
int pows[25][1005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    scanf("%s",a);
    int sum_q=0;
    int i;
    memset(tag,-1,sizeof(tag));
    for (i=0;i<n;i++)
    {
        if (a[i]=='?')
        {
            sum_q++;
        }
    }
    for (i=0;i<=n;i++)
    {
        int j;
        for (j=0;j<=20;j++)
        {
            pows[j][i]=power(j,i);
        }
    }
    for (i=0;i<=n;i++)
    {
        int j;
        for (j=0;i+j<=n;j++)
        {
            if (i<=1)
            {
                tag[j][i+j]=0;
                anys[j][i+j]=sum_q;
            }
            else
            {
                anys[j][i+j]=anys[j+1][i+j-1];
                if (a[j]==a[i+j-1])
                {
                    tag[j][i+j]=tag[j+1][i+j-1];
                }
                else if (a[j]=='?')
                {
                    tag[j][i+j]=tag[j+1][i+j-1]|(1<<(a[i+j-1]-'a'));
                    anys[j][i+j]--;
                }
                else if (a[i+j-1]=='?')
                {
                    tag[j][i+j]=tag[j+1][i+j-1]|(1<<(a[j]-'a'));
                    anys[j][i+j]--;
                }
                if ((a[j]=='?')&&(a[i+j-1]=='?'))
                {
                    anys[j][i+j]--;
                }
                if (tag[j+1][i+j-1]==-1)
                {
                    tag[j][i+j]=-1;
                }
            }
            if ((tag[j][i+j]!=-1)&&(i>=1))
            {
                int k;
                for (k=0;k<=17;k++)
                {
                    ans[tag[j][i+j]][k]=(ans[tag[j][i+j]][k]+pows[k][anys[j][i+j]])%modo;
                }
            }
        }
    }
    for (i=0;i<=17;i++)
    {
        int j,k;
        for (k=0;k<17;k++)
        {
            for (j=0;j<(1<<17);j++)
            {
                if ((1<<k)&j)
                {
                    continue;
                }
                ans[j^(1<<k)][i]=(ans[j^(1<<k)][i]+ans[j][i])%modo;
            }
        }
    }
    int q;
    scanf("%d",&q);
    for (i=0;i<q;i++)
    {
        scanf("%s",b);
        int j;
        int r=0;
        for (j=0;b[j]!='\0';j++)
        {
            r^=(1<<(b[j]-'a'));
        }
        printf("%d\n",ans[r][j]);
    }
    return 0;
}