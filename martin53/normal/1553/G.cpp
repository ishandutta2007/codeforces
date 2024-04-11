#include<bits/stdc++.h>
using namespace std;

const int nmax=1.5e5+42,MX=1e6+42;

int min_div[MX];

void prec()
{
    for(int i=2;i<MX;i++)
        if(min_div[i]==0)
        {
            for(int j=i;j<MX;j=j+i)
                if(min_div[j]==0)min_div[j]=i;
        }
}

vector<int> seen[MX];

int n,inp[nmax];
int q;

int parent[nmax];
int root(int node)
{
    if(node==parent[node])return node;
    parent[node]=root(parent[node]);
    return parent[node];
}

set<int> primes_in[nmax],primes_can_get[nmax];

map< pair<int,int>, int> mem;

bool common(int LHS,int RHS)
{
    if(primes_in[LHS].size()<primes_can_get[RHS].size())
    {
        for(auto w:primes_in[LHS])
            if(primes_can_get[RHS].count(w))return 1;

        return 0;
    }

    for(auto w:primes_can_get[RHS])
        if(primes_in[LHS].count(w))return 1;

    return 0;

}

set< pair<int,int> > edges;

int ask()
{
    int p,q;

    scanf("%i%i",&p,&q);

    p=root(p);
    q=root(q);

    if(p>q)swap(p,q);

    if(p==q)return 0;

    if(edges.count({p,q}))return 1;

    if(mem.count({p,q}))return mem[{p,q}];

    if(common(p,q)||common(q,p))mem[{p,q}]=1;
    else mem[{p,q}]=2;

    return mem[{p,q}];
}

vector<int> get_dvd(int val)
{
    int prv=0;

    vector<int> ret={};

    while(val!=1)
    {
        if(prv!=min_div[val])ret.push_back(min_div[val]);

        prv=min_div[val];

        val=val/prv;
    }

    return ret;
}

int where[MX];

int main()
{
    prec();

    scanf("%i%i",&n,&q);

    for(int i=1;i<=n;i++)parent[i]=i;

    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);

        vector<int> help=get_dvd(inp[i]);

        for(auto w:help)
            seen[w].push_back(i);
    }

    for(int i=1;i<MX;i++)
    {
        for(int j=1;j<seen[i].size();j++)
        {
            int p=seen[i][0];
            int q=seen[i][j];

            parent[root(p)]=root(q);
        }
    }

    //for(int i=1;i<=n;i++)cout<<i<<" -> "<<root(i)<<endl;

    for(int i=1;i<=n;i++)
    {
        int id=root(i);

        for(auto w:get_dvd(inp[i]))
        {
            primes_in[id].insert(w);
            where[w]=id;
        }

        for(auto w:get_dvd(inp[i]+1))
            primes_can_get[id].insert(w);
    }

    for(int i=1;i<=n;i++)
    {
        vector<int> help={};

        for(auto w:get_dvd(inp[i]+1))
        {
            if(where[w])help.push_back(where[w]);
        }

        for(auto p:help)
            for(auto q:help)
                if(p<q)edges.insert({p,q});
    }

    /*
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" : "<<endl;
        cout<<"in: ";for(auto w:primes_in[i])cout<<w<<" ";cout<<endl;
        cout<<"can_get: ";for(auto w:primes_can_get[i])cout<<w<<" ";cout<<endl;
    }
    */

    for(int i=1;i<=q;i++)
        printf("%i\n",ask());

    return 0;
}