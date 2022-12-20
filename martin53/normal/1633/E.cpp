#include<bits/stdc++.h>
using namespace std;

const int MX=3e2+42,inf=1e9+42;

int n,m;

struct edge
{
    int u,v,c;
    int id;
};
edge inp[MX];

int parent[MX];
int root(int node)
{
    if(parent[node]==node)return node;
    parent[node]=root(parent[node]);
    return parent[node];
}

struct result
{
    vector<int> edges;
    long long a,b;//ax+b
};

vector< pair< pair<int,int>, pair<long long,long long> > > seen;

void add(int l,int r,long long a,long long b)
{
    seen.push_back({{l,r},{a,b}});
}

int X_NOW;
bool cmp(edge a,edge b)
{
    if(abs(a.c-X_NOW)!=abs(b.c-X_NOW))return abs(a.c-X_NOW)<abs(b.c-X_NOW);
    return a.id<b.id;
}

result eval(int x)
{
    X_NOW=x;

    sort(inp+1,inp+m+1,cmp);

    result ret;
    ret.edges={};
    ret.a=0;
    ret.b=0;

    for(int i=1;i<=n;i++)parent[i]=i;

    for(int i=1;i<=m;i++)
        if(root(inp[i].u)!=root(inp[i].v))
        {
            parent[root(inp[i].u)]=root(inp[i].v);
            ret.edges.push_back(inp[i].id);

            if(inp[i].c<=x)ret.a++,ret.b-=inp[i].c;
            else ret.a--,ret.b+=inp[i].c;
        }

    return ret;
}

void rec(int l,result LHS,int r,result RHS)
{
    if(LHS.a==RHS.a&&LHS.b==RHS.b&&LHS.edges==RHS.edges)
    {
        add(l,r,LHS.a,LHS.b);
        return;
    }

    if(l+1==r)
    {
        add(l,l,LHS.a,LHS.b);
        add(r,r,RHS.a,RHS.b);
        return;
    }

    int av=(l+r)/2;

    result cur=eval(av);

    rec(l,LHS,av,cur);
    rec(av,cur,r,RHS);
}

long long cost(int x)
{
    int pos=lower_bound(seen.begin(),seen.end(),make_pair(make_pair(x,inf),make_pair(1LL*inf,1LL*inf)))-seen.begin();

    pos--;

    return 1LL*seen[pos].second.first*x+seen[pos].second.second;
}

int main()
{
    scanf("%i%i",&n,&m);

    for(int i=1;i<=m;i++)
    {
        scanf("%i%i%i",&inp[i].u,&inp[i].v,&inp[i].c);
        inp[i].id=i;
    }

    int p,k,a,b,c;
    scanf("%i%i%i%i%i",&p,&k,&a,&b,&c);

    rec(0,eval(0),c,eval(c));

    /*
    for(auto w:seen)
    {
        cout<<w.first.first<<" "<<w.first.second<<" "<<w.second.first<<" "<<w.second.second<<endl;
    }
    */

    long long outp=0;

    long long lst=0;

    for(int i=1;i<=p;i++)
    {
        scanf("%lld",&lst);

        outp=outp^cost(lst);
    }

    for(int i=p+1;i<=k;i++)
    {
        lst=(lst*a+b)%c;

        outp=outp^cost(lst);
    }

    printf("%lld\n",outp);

    return 0;
}