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
char a[200005],b[200005];
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
        scanf("%d%s%s",&n,a,b);
        int i;
        for (i=n-1;i>=0;i--)
        {
            if ((a[i]!='.')||(b[i]!='.'))
            {
                break;
            }
        }
        n=i;
        for (i=0;i<=n;i++)
        {
            if ((a[i]!='.')||(b[i]!='.'))
            {
                break;
            }
        }
        int dp_up=0,dp_down=0;
        int last_up=0,last_down=0;
        if (a[i]=='*')
        {
            last_down=1;
        }
        if (b[i]=='*')
        {
            last_up=1;
        }
        for (i++;i<=n;i++)
        {
            if (a[i]=='*')
            {
                dp_down=min(last_up+2,last_down+2);
            }
            else
            {
                dp_down=min(last_up+2,last_down+1);
            }
            if (b[i]=='*')
            {
                dp_up=min(last_up+2,last_down+2);
            }
            else
            {
                dp_up=min(last_up+1,last_down+2);
            }
            last_up=dp_up;
            last_down=dp_down;
        }
        printf("%d\n",min(last_up,last_down));
    }
    return 0;
}