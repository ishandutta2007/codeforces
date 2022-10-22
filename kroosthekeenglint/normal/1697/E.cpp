#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<memory>
#include<time.h>
#include<math.h>
#include<bitset>
#include<fstream>
#include<sstream>
#include<stdio.h>
#include<utility>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct point
{
    int x;
    int y;
    point (int xx=0,int yy=0)
    {
        x=xx;
        y=yy;
    }
    void read()
    {
        scanf("%d%d",&x,&y);
    }
    friend point operator - (const point &a,const point &b)
    {
        return point(a.x-b.x,a.y-b.y);
    }
    long long dist()
    {
        return abs(x)+abs(y);
    }
};
point a[105];
int min_dist[105];
int edges[105][105];
const int modo=998244353;
int cnt[5];
int c[105][105];
int p[105][105];
void calc_c_and_p()
{
    int i,j;
    c[0][0]=1;
    p[0][0]=1;
    for (i=1;i<=100;i++)
    {
        c[i][0]=1;
        p[i][0]=1;
        for (j=1;j<=i;j++)
        {
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%modo;
            p[i][j]=(p[i][j-1]*(long long)(i-j+1))%modo;
        }
    }
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    for (i=0;i<n;i++)
    {
        a[i].read();
    }
    for (i=0;i<n;i++)
    {
        int j;
        long long min_val=1234567890123456789ll;
        min_dist[i]=-1;
        for (j=0;j<n;j++)
        {
            if (i!=j)
            {
                if ((a[i]-a[j]).dist()<min_val)
                {
                    min_val=(a[i]-a[j]).dist();
                    min_dist[i]=j;
                }
            }
        }
        for (j=0;j<n;j++)
        {
            if (i!=j)
            {
                if ((a[i]-a[j]).dist()==min_val)
                {
                    edges[i][j]=true;
                }
            }
        }
    }
    for (i=0;i<n;i++)
    {
        int j;
        int sum=1;
        for (j=0;j<n;j++)
        {
            if (j==i)
            {
                continue;
            }
            if (!edges[i][j])
            {
                continue;
            }
            sum++;
            if (!edges[j][i])
            {
                break;
            }
            int k;
            for (k=0;k<n;k++)
            {
                if ((k==i)||(k==j))
                {
                    continue;
                }
                if ((edges[j][k])||(edges[i][k]))
                {
                    if ((edges[j][k])&&(edges[i][k]))
                    {
                        if ((!edges[k][j])||(!edges[k][i]))
                        {
                            break;
                        } 
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if (k!=n)
            {
                break;
            }
        }
        if (j==n)
        {
            cnt[sum]++;
        }
    }
    //printf("%d %d %d\n",cnt[2],cnt[3],cnt[4]);
    calc_c_and_p();
    cnt[2]/=2;
    cnt[3]/=3;
    cnt[4]/=4;
    cnt[5]/=5;
    int ans=0;
    for (i=0;i<=cnt[2];i++)
    {
        int j,k,l;
        for (j=0;j<=cnt[3];j++)
        {
            for (k=0;k<=cnt[4];k++)
            {
                for (l=0;l<=cnt[5];l++)
                {
                    ans=(ans+(long long)p[n][n-i-j*2-k*3-l*4]*c[cnt[2]][i]%modo*c[cnt[3]][j]%modo*c[cnt[4]][k]%modo*c[cnt[5]][l])%modo;
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}