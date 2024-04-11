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
long long a[1005];
long long b[1005];
int n;
int flag;
int ans[1005];
void check(int x)
{
    int i;
    set<pair<long long,int> > aa;
    set<pair<long long,int> > bb;
    aa.clear();
    bb.clear();
    for (i=0;i<n;i++)
    {
        aa.insert(make_pair(a[i], i));
        bb.insert(make_pair(b[i], i));
    }
    int min_val = -x;
    for (i=n-1;i>=0;i--)
    {
        set<pair<long long,int> >::iterator ii = aa.end();
        ii--;
        set<pair<long long,int> >::iterator jj = bb.end();
        jj--;
        if ((*ii).first > (*jj).first)
        {
            set<pair<long long,int> >::iterator t = bb.lower_bound(make_pair(abs((*ii).first - x), 0));
            if ((t == bb.end()) || ((*t).first != abs((*ii).first - x)))
            {
                //not ok 
                return;
            }
            ans[i] = -(*ii).first;
            min_val = min(min_val, ans[i]);
            aa.erase(ii);
            bb.erase(t);
        }
        else
        {
            set<pair<long long,int> >::iterator t = aa.lower_bound(make_pair(abs((*jj).first - x), 0));
            if ((t == aa.end()) || ((*t).first != abs((*jj).first - x)))
            {
                //not ok 
                return;
            }
            ans[i] = (*jj).first - x;
            min_val = min(min_val, ans[i]);
            aa.erase(t);
            bb.erase(jj);
        }
    }
    if (i == -1)
    {
        printf("YES\n");
        for (i=0;i<n;i++)
        {
            printf("%d ",ans[i] - min_val);
        }
        printf("\n");
        printf("%d %d\n",0 - min_val, - x - min_val);
        flag = 1;
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
        scanf("%d",&n);
        int i;
        for (i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
        }
        for (i=0;i<n;i++)
        {
            scanf("%lld",&b[i]);
        }
        sort(a,a+n);
        sort(b,b+n);
        flag = 0;
        for (i=0;i<n;i++)
        {
            check(abs(a[0]-b[i]));
            if (flag == 1)
            {
                break;
            }
            check(abs(a[0]+b[i]));
            if (flag == 1)
            {
                break;
            }
        }
        if (flag == 0)
        {
            puts("NO");
        }
    }
    return 0;
}