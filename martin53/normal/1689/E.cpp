#include<bits/stdc++.h>
using namespace std;

const int nmax=2e3+42,C=30;

int n,inp[nmax];
int outp;

bool been[C];
int parent[C];

int root(int node)
{
    if(node==parent[node])return node;
    parent[node]=root(parent[node]);
    return parent[node];
}

void my_merge(int u,int v)
{
    u=root(u);
    v=root(v);
    parent[u]=v;
}

bool check()
{
    for(int i=1;i<=n;i++)
        if(inp[i]==0)return 0;

    for(int i=0;i<C;i++)
    {
        been[i]=0;
        parent[i]=i;
    }

    for(int i=1;i<=n;i++)
    {
        vector<int> bits={};

        for(int j=0;j<C;j++)
            if((inp[i]&(1<<j)))
            {
                bits.push_back(j);
                been[j]=1;
            }

        for(int j=1;j<bits.size();j++)
            my_merge(bits[j-1],bits[j]);
    }

    int start=0;

    while(been[start]==0)start++;

    for(int i=0;i<C;i++)
        if(been[i]&&root(i)!=root(start))return 0;

    return 1;
}

void print()
{
    printf("%i\n",outp);
    for(int i=1;i<=n;i++)printf("%i ",inp[i]);
    printf("\n");
}

void solve()
{
    outp=0;

    scanf("%i",&n);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=1;i<=n;i++)
        if(inp[i]==0)
        {
            inp[i]++;
            outp++;
        }

    if(check())
    {
        print();
        return;
    }

    for(int i=1;i<=n;i++)
    {
        inp[i]--;
        outp++;

        if(check())
        {
            print();
            return;
        }

        inp[i]++;
        inp[i]++;

        if(check())
        {
            print();
            return;
        }

        outp--;
        inp[i]--;
    }

    int MX=0;

    for(int j=1;j<=n;j++)
        MX=max(MX,(inp[j]&(-inp[j])));

    vector<int> ids={};

    for(int j=1;j<=n;j++)
        if((inp[j]&(-inp[j]))==MX)
            ids.push_back(j);

    outp+=2;
    inp[ids[0]]--;
    inp[ids[1]]++;

    print();
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        solve();
    }

    return 0;
}