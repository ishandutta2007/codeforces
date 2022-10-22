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
int p[200005];
int s[200005];
int childs[200005];
struct edge
{
    int y;
    edge * next;
};
edge * new_edge()
{
    static edge a[500005];
    static int top=0;
    return &a[top++];
}
edge * li[200005];
void insert_edge(int x,int y)
{
    edge * t = new_edge();
    t->y=y;
    t->next=li[x];
    li[x]=t;
}
long long ans[200005];
long long final_ans;
vector<pair<long long,int> > v[200005];
void find_max_path(int x)
{
    if (x == -1)
    {
        return;
    }
    pair<long long,int> t = v[x][v[x].size()-1];
    v[x].pop_back();
    final_ans += s[x];
    find_max_path(t.second);
    ans[x] = s[x] + v[x][v[x].size()-1].first;
}
void dfs(int x,int k)
{
    final_ans += (long long)s[x] * k;
    edge * t;
    for (t=li[x];t!=0;t=t->next)
    {
        dfs(t->y, k/childs[x]);
        v[x].push_back(make_pair(ans[t->y],t->y));
    }
    v[x].push_back(make_pair(0ll,-1));
    sort(v[x].begin(),v[x].end());
    int i;
    ans[x] = s[x] + v[x][v[x].size()-1].first;
    if (childs[x] != 0)
    {
        for (i=0;i<k%childs[x];i++)
        {
            final_ans -= s[x];
            find_max_path(x);
        }
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
        int n,k;
        scanf("%d%d",&n,&k);
        int i;
        for (i=0;i<n;i++)
        {
            li[i] = 0;
            childs[i] = 0;
            ans[i] = 0;
            v[i].clear();
        }
        final_ans = 0;
        for (i=1;i<n;i++)
        {
            scanf("%d",&p[i]);
            p[i]--;
            insert_edge(p[i], i);
            childs[p[i]] ++;
        }
        for (i=0;i<n;i++)
        {
            scanf("%d",&s[i]);
        }
        dfs(0, k);
        printf("%lld\n",final_ans);
    }
    return 0;
}