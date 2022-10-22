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
char a[505][505];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int zu;
    scanf("%d",&zu);
    int n,m;
    int t;
    for (t=0;t<zu;t++)
    {
        scanf("%d%d",&n,&m);
        int i;
        for (i=0;i<n;i++)
        {
            scanf("%s",a[i]);
        }
        for (i=0;i<=m;i++)
        {
            a[n][i] = '\0';
        }
        int j;
        int cnt_1 = 0;
        int have_0 = 0, cos_0 = 0;
        for (i=0;i<n;i++)
        {
            for (j=0;j<m;j++)
            {
                if (a[i][j] == '0')
                {
                    have_0 = 1;
                    if ((a[i+1][j] == '0') || (a[i][j+1] == '0') || (a[i+1][j+1] == '0'))
                    {
                        cos_0 = 1;
                    }
                    if ((j>=1) && (a[i+1][j-1] == '0'))
                    {
                        cos_0 = 1;
                    }
                }
                else
                {
                    cnt_1 ++;
                }
            }
        }
        printf("%d\n",cnt_1 - 2 + have_0 + cos_0);
    }
    return 0;
}