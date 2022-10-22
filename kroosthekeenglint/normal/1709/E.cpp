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
struct edge
{
    int y;
    edge * next; 
};
edge * li[200005];
edge * new_edge()
{
    static edge a[400005];
    static int top=0;
    return &a[top++];
}
void inserts(int x,int y)
{
    edge * t=new_edge();
    t->y=y;
    t->next=li[x];
    li[x]=t;
}
void insert_edge(int x,int y)
{
    inserts(x,y);
    inserts(y,x);
}
int xors[200005];
int fa[200005];
int a[200005];
void dfs1(int x)
{
    edge * t;
    for (t=li[x];t!=0;t=t->next)
    {
        if (fa[x] == t->y)
        {
            continue;
        }
        xors[t->y] = xors[x] ^ a[t->y];
        fa[t->y] = x;
        dfs1(t->y);
    }
}
int ans=0;
set<int> s[200005];
bool cmp(set<int> * x, set<int> * y)
{
    return x->size() > y->size();
} 
set<int> * dfs2(int x)
{
    edge * t;
    vector<set<int> * > v;
    for (t=li[x];t!=0;t=t->next)
    {
        if (fa[x] == t->y)
        {
            continue;
        }
        v.push_back(dfs2(t->y));
    }
    if (v.size()==0)
    {
        s[x].insert(xors[x]);
        return &s[x];
    }
    else
    {
        sort(v.begin(),v.end(),cmp);
        if (v[0]->find(xors[x]^a[x]) != v[0]->end())
        {
            ans++;
            return &s[x];
        }
        v[0]->insert(xors[x]);
        int i;
        for (i=1;i<v.size();i++)
        {
            set<int>::iterator ii;
            for (ii=v[i]->begin();ii!=v[i]->end();ii++)
            {
                if (v[0]->find((*ii) ^ a[x]) != v[0]->end())
                {
                    ans++;
                    return &s[x];
                }
            }
            for (ii=v[i]->begin();ii!=v[i]->end();ii++)
            {
                v[0]->insert(*ii);
            }
        }
        return v[0];
    }
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        fa[i]=-1;
    }
    for (i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x--;
        y--;
        insert_edge(x,y);
    }
    xors[0] = a[0];
    dfs1(0);
    dfs2(0);
    printf("%d\n",ans);
    return 0;
}