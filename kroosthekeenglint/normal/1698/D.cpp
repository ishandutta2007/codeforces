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
bool query(int l,int r)
{
    printf("? %d %d\n",l+1,r+1);
    fflush(stdout);
    int i;
    int sum=0;
    for (i=l;i<=r;i++)
    {
        int x;
        scanf("%d",&x);
        x--;
        if ((l<=x)&&(x<=r))
        {
            sum^=1;
        }
    }
    return sum;
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
        int l=0,r=n;
        for (;l<=r;)
        {
            int mid=(l+r)/2;
            if (query(l,mid))
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        printf("! %d\n",l+1);
        fflush(stdout);
    }
    return 0;
}