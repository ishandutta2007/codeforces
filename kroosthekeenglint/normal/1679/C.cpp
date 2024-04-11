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
multiset<int> a;
multiset<int> b;
int cnt_a[100005],cnt_b[100005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,q;
    scanf("%d%d",&n,&q);
    int i;
    for (i=0;i<n;i++)
    {
        a.insert(i);
        b.insert(i);
    }
    for (i=0;i<q;i++)
    {
        int op;
        scanf("%d",&op);
        if (op==1)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            x--;
            y--;
            cnt_a[x]++;
            if (cnt_a[x]==1)
            {
                a.erase(x);
            }
            cnt_b[y]++;
            if (cnt_b[y]==1)
            {
                b.erase(y);
            }
        }
        else if (op==2)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            x--;
            y--;
            cnt_a[x]--;
            if (cnt_a[x]==0)
            {
                a.insert(x);
            }
            cnt_b[y]--;
            if (cnt_b[y]==0)
            {
                b.insert(y);
            }
        }
        else if (op==3)
        {
            int x1,x2,y1,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            x1--;
            y1--;
            if ((a.lower_bound(x1)==a.lower_bound(x2))||(b.lower_bound(y1)==b.lower_bound(y2)))
            {
                puts("Yes");
            }
            else
            {
                puts("No");
            }
        }
    }
    return 0;
}