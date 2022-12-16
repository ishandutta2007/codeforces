#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize ("unroll-loops")

#include<bits/stdc++.h>
using namespace std;
const int nmax=5e4+42;
int n,m,q;
unordered_map<int,int> adj[nmax];
bool on[nmax];
unordered_set<int> heavy;//adj.size()<=LIM => light, > => heavy
int cnt[nmax],LIM;

void add_edge(int from,int to)
{
    adj[from][to]=1;
    if(adj[from].size()<=LIM)return;//still light
    if(adj[from].size()==LIM+1)//light to heavy
    {
        heavy.insert(from);
        cnt[from]=0;
        for(auto k:adj[from])
            if(k.second)cnt[from]+=on[k.first];
        return;
    }
    //heavy to heavy
    cnt[from]+=on[to];
}

void delete_edge(int from,int to)
{
    adj[from][to]=0;
    if(adj[from].size()>LIM)//still heavy
    {
        cnt[from]-=on[to];
        return;
    }
    //heavy to light
    //light to light
}
void update(int node,int val)
{
    on[node]+=val;
    for(auto k:heavy)
        if(adj[k].count(node)&&adj[k][node])cnt[k]+=val;
}
int main()
{
    scanf("%i%i%i",&n,&m,&q);

    LIM=1200;

    int o,a,b;
    scanf("%i",&o);
    for(int i=1;i<=o;i++)
    {
        scanf("%i",&a);
        on[a]=1;
    }

    for(int i=1;i<=m;i++)
    {
        scanf("%i%i",&a,&b);
        add_edge(a,b);
        add_edge(b,a);
    }

    char c;
    for(int i=1;i<=q;i++)
    {
        c=getchar();
        while(c!='O'&&c!='F'&&c!='A'&&c!='D'&&c!='C')c=getchar();
        if(c=='O')
        {
            scanf("%i",&a);
            update(a,1);
        }
        if(c=='F')
        {
            scanf("%i",&a);
            update(a,-1);
        }
        if(c=='C')
        {
            scanf("%i",&a);
            if(heavy.count(a))
                printf("%i\n",cnt[a]);
            else
            {
                int out=0;
                for(auto k:adj[a])
                    if(k.second)out=out+on[k.first];
                printf("%i\n",out);
            }
        }
        if(c=='A')
        {
            scanf("%i%i",&a,&b);
            add_edge(a,b);
            add_edge(b,a);
        }
        if(c=='D')
        {
            scanf("%i%i",&a,&b);
            delete_edge(a,b);
            delete_edge(b,a);
        }
    }
    return 0;
}