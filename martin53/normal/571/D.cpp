#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize ("unroll-loops")

#include<bits/stdc++.h>
using namespace std;
const int nmax=5e5+42;

int n,q;
int SZ_uni[nmax],parent_uni[nmax],time_uni[nmax];

int SZ_mil[nmax],parent_mil[nmax],time_mil[nmax];
int last_raid[nmax];

vector< pair<int/*size of update*/,int/*time*/> > added[nmax];
vector< long long/*sums*/ > prefix[nmax];

int root_uni(int node)
{
    while(parent_uni[node]!=node)node=parent_uni[node];
    return node;
}

int root_mil(int node)
{
    while(parent_mil[node]!=node)node=parent_mil[node];
    return node;
}

long long query()
{
    int node;
    scanf("%i",&node);

    int cnode=node,last_raid_now=0,ignore_before=0;
    while(1)
    {
        if(last_raid[node]>ignore_before)last_raid_now=max(last_raid_now,last_raid[node]);
        ignore_before=max(ignore_before,time_mil[node]);
        if(node==parent_mil[node])break;
        node=parent_mil[node];
    }
    /*
    cout<<"last_raid_now: "<<last_raid_now<<endl;
    cout<<"time_mil: ";for(int i=1;i<=n;i++)cout<<time_mil[i]<<" ";cout<<endl;
    */

    node=cnode;
    long long ret=0;
    while(1)
    {
        if(prefix[node].size())
        {
            int ok=prefix[node].size(),not_ok=-1;

            ret=ret+prefix[node][ok-1];

            while(ok-not_ok>1)
            {
                int av=(ok+not_ok)/2;
                if(added[node][av].second>last_raid_now)ok=av;
                else not_ok=av;
            }
            if(ok)ret=ret-prefix[node][ok-1];
        }


        last_raid_now=max(last_raid_now,time_uni[node]);
        if(node==parent_uni[node])break;
        node=parent_uni[node];
    }
    return ret;
}
char find_type()
{
    char c=getchar();
    while('A'>c||c>'Z')c=getchar();
    return c;
}
int main()
{
    scanf("%i%i",&n,&q);

    for(int i=1;i<=n;i++)SZ_uni[i]=1,parent_uni[i]=i;
    for(int i=1;i<=n;i++)SZ_mil[i]=1,parent_mil[i]=i;

    char c;
    for(int i=1;i<=q;i++)
    {
        c=find_type();
        if(c=='U')
        {
            int a,b;
            scanf("%i%i",&a,&b);
            a=root_uni(a);
            b=root_uni(b);
            if(SZ_uni[a]<SZ_uni[b])swap(a,b);
            time_uni[b]=i;
            parent_uni[b]=a;
            SZ_uni[a]+=SZ_uni[b];
        }

        if(c=='M')
        {
            int c,d;
            scanf("%i%i",&c,&d);
            c=root_mil(c);
            d=root_mil(d);
            if(SZ_mil[c]<SZ_mil[d])swap(c,d);
            time_mil[d]=i;
            parent_mil[d]=c;
            SZ_mil[c]+=SZ_mil[d];
        }

        if(c=='Z')
        {
            int y;
            scanf("%i",&y);
            y=root_mil(y);
            last_raid[y]=i;
        }

        if(c=='A')
        {
            int x;
            scanf("%i",&x);
            x=root_uni(x);

            long long prev=0;
            if(added[x].size())prev=prefix[x][added[x].size()-1];
            prev=prev+SZ_uni[x];

            added[x].push_back({SZ_uni[x],i});
            prefix[x].push_back(prev);
        }

        if(c=='Q')
            printf("%lld\n",query());
    }
}