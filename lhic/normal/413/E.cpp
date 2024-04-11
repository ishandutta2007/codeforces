#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <bitset>
#include <cstdlib>

typedef long long ll;
typedef long double ld;

using namespace std;

int n,m;

bool arr[2][300000];

int dp[700000];

int up[700000];


int was[700000];

int now;

void DFS(int x,int y,int d)
{
    was[y+x*n]=now;
    dp[y+x*n]=d;



    if (y+1<n &&   !was[y+1+x*n] && !arr[x][y+1])
    {
        DFS(x,y+1,d+1);
    }

    if (!was[y+(1-x)*n] && !arr[(1-x)][y])
    {
        DFS(1-x,y,d+1);
    }
}


void init()
{
    for (int i=0;i<2;++i)
    {
        int lst=n;
        for (int j=n-1;j>=0;--j)
            if (arr[i][j])
                lst=j;
            else
                up[j+i*n]=lst;
    }


    for (int j=0;j<n;++j)
    {
        for (int i=0;i<2;++i)
        {
            if (!was[j+i*n] && !arr[i][j])
            {
                ++now;
                DFS(i,j,0);
            }
        }
    }



}


int main()
{
    //ios_base::sync_with_stdio(false);


    scanf("%d %d ",&n,&m);

    for (int i=0;i<2;++i)
        for (int j=0;j<n;++j)
        {
            char a;
            scanf("%c ",&a);
            if (a=='X')
                arr[i][j]=true;
            else
                arr[i][j]=false;
        }

    init();


    for (int i=0;i<m;++i)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        --a;
        --b;
        int a1=a%n;
        int b1=b%n;
        if (a1==b1)
        {
            if (a==b)
                printf("0\n");
            else
                printf("1\n");
            continue;
        }
        if (a1>b1)
        {
            swap(a1,b1);
            swap(a,b);
        }

        if (was[a]!=was[b])
        {
            printf("-1\n");
            continue;
        }

        if (a<n)
        {
            if (dp[a]<dp[a+n] || (up[a]>b1 && a/n==b/n) || (up[a] > up[a+n] && b1>up[a+n] ) )
                printf("%d\n",dp[b]-dp[a]);
            else
                printf("%d\n",dp[b]-dp[a+n]+1);
        }
        else
        {
            if (dp[a]<dp[a-n] || (up[a]>b1 && a/n==b/n) || (up[a] > up[a-n] && b1>up[a-n] ) )
                printf("%d\n",dp[b]-dp[a]);
            else
                printf("%d\n",dp[b]-dp[a-n]+1);
        }
    }


    return 0;
}