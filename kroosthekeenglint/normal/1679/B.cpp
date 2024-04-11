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
int a[200005];
int last_op[200005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    int n,q;
    scanf("%d%d",&n,&q);
    int i;
    long long cur_sum=0;
    int cur_replace=0,replace_op=-2;
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        cur_sum+=a[i];
        last_op[i]=-1;
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
            if (last_op[x]<replace_op)
            {
                cur_sum-=cur_replace;
            }
            else
            {
                cur_sum-=a[x];
            }
            a[x]=y;
            cur_sum+=y;
            last_op[x]=i;
        }
        else
        {
            scanf("%d",&cur_replace);
            replace_op=i;
            cur_sum=cur_replace*(long long)n;
        }
        cout<<cur_sum<<"\n";
    }
    return 0;
}