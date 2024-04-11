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
int n;
int x[200005];
int t[200005];
struct seg
{
    int l;
    int r;
    seg(int ll=0,int rr=0)
    {
        l=ll;
        r=rr;
    }
    friend seg operator + (const seg &a,const seg &b)
    {
        return seg(max(a.l,b.l),min(a.r,b.r));
    }
};
int check(int val)
{
    int i;
    seg now(0,300000000);
    for (i=0;i<n;i++)
    {
        now = now + seg(x[i] - (val - t[i]), x[i] + (val - t[i]));
    }
    if (now.l <= now.r)
    {
        return now.l;
    }
    return -1;
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int tt;
    scanf("%d",&tt);
    int zu;
    for (zu=0;zu<tt;zu++)
    {
        scanf("%d",&n);
        int i;
        for (i=0;i<n;i++)
        {
            scanf("%d",&x[i]);
            x[i] *= 2;
        }
        for (i=0;i<n;i++)
        {
            scanf("%d",&t[i]); 
            t[i] *= 2;
        }
        int l = 0, r = 300000000;
        for (;l<=r;)
        {
            int mid = (l + r) / 2;
            if (check(mid) != -1)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        printf("%.12lf\n",check(l)*0.5);
    }
    return 0;
}