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
int a[100005];
char ans[100005];
int n,q;
bool check(int x)
{
    int i;
    int now_q=q;
    for (i=x;i<n;i++)
    {
        if (a[i]>now_q)
        {
            now_q--;
        }
    }
    if (now_q>=0)
    {
        return true;
    }
    else
    {
        return false;
    }
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
        scanf("%d%d",&n,&q);
        int i;
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if (a[i]<=q)
            {
                ans[i]='1';
            }
            else
            {
                ans[i]='0';
            }
        }
        int l=0,r=n;
        for (;l<=r;)
        {
            int mid=(l+r)/2;
            if (check(mid))
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            } 
        }
        for (i=l;i<n;i++)
        {
            ans[i]='1';
        }
        ans[n]='\0';
        printf("%s\n",ans);
    }
    return 0;
}