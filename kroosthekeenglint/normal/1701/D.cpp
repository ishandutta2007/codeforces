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
struct new_seg
{
    int val;
    int i;
    int l;
    int r;
    void read()
    {
        scanf("%d",&val);
    }
    void calc_lr()
    {
        // i / ai = val (val <= i / ai < (val + 1) ) 
        // val * ai <= i < (val + 1) * ai
        // ai <= i / val && ai > i / (val + 1)
        l = i / (val + 1) + 1;
        if (val == 0)
        {
            r = n;
        }
        else
        {
            r = i / val;
        }
    }
    friend bool operator < (const new_seg &a,const new_seg &b)
    {
        if (a.l==b.l)
        {
            return a.r<b.r;
        }
        return a.l<b.l;
    }
};
new_seg b[500005];
int a[500005];
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
        scanf("%d",&n);
        int i;
        for (i=0;i<n;i++)
        {
            b[i].read();
            b[i].i = i+1;
            b[i].calc_lr();
        }
        sort(b,b+n);
        priority_queue<pair<int,int> > q;
        int j = 0;
        for (i=1;i<=n;i++)
        {
            for (;j<n;j++)
            {
                if (b[j].l <= i)
                {
                    q.push(make_pair(-b[j].r,b[j].i));
                }
                else
                {
                    break;
                }
            }
            int now = q.top().second;
            q.pop();
            a[now]=i;
        }
        for (i=1;i<=n;i++)
        {
            printf("%d ",a[i]); 
        }
        printf("\n");
    }
    return 0;
}