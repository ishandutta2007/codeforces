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
struct tt
{
    int num;
    tt * next;
};
int cur_p[100005];
int a[100005];
int ans[100005];
tt * v[100005];
tt b[100005];
const int sqrtn = 320;
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
        int n,k;
        scanf("%d%d",&n,&k);
        int i;
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            b[i].num = i;
        }
        for (i=0;i<=100000;i++)
        {
            v[i]=0;
        }
        for (i=0;i<n;i++)
        {
            cur_p[i] = 1;
            b[i].next = v[a[i]];
            v[a[i]] = &b[i];
        }
        int min_ans = 1000005;
        int min_val = a[0];
        for (i=100000;i>=a[n-1]/k;i--)
        {
            min_ans=min(min_ans,i-min_val);
            tt * j;
            for (j=v[i];j!=0;)
            {
                int x = j->num;
                cur_p[x]++;
                int t = cur_p[x];
                if (a[x]/t == i)
                {
                    if (i==0)
                    {
                        j = j->next;
                        continue;
                    }
                    t = a[x]/i + 1;
                    cur_p[x] = t-1;
                    if (t>k)
                    {
                        j = j->next;
                        continue;
                    }
                }
                tt * temp = j->next;
                j->next = v[a[x]/t];
                v[a[x]/t] = j;
                min_val = min(min_val, a[x]/t);
                j = temp;
            }
        }
        printf("%d\n",min_ans);
    }
    return 0;
}