#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;

struct edge
{
    int u,v,sum;
};

void wrong()
{
    printf("NO\n");
    exit(0);
}

edge inp[nmax];

int parent[nmax];

int n,m;

int root(int node)
{
    if(parent[node]==node)return node;
    parent[node]=root(parent[node]);
    return parent[node];
}
vector< pair<int/*node*/,int/*sum*/> > adj[nmax];

double outp[nmax];

set< int > half_x;

pair<int/*a coeff*/,int/*b coeff*/> help[nmax];//a_coeff*x+b_coeff

vector<int> component={};

void dfs(int node,int a_coeff,int b_coeff)
{
    if(help[node].first==0)
    {
        component.push_back(node);
        help[node]={a_coeff,b_coeff};
    }
    else
    {
        //x*help[node].first+help[node].second=x*a_coeff+b_coeff
        //x*(help[node].first-a_coeff)=b_coeff-help[node].second

        int up=b_coeff-help[node].second;
        int down=help[node].first-a_coeff;

        if(down==0)
        {
            if(up)wrong();
        }
        else
        {
            if(down<0)down=-down,up=-up;

            half_x.insert(up);
        }
        return;
    }

    for(auto k:adj[node])
        dfs(k.first,-a_coeff,k.second-b_coeff);
}

long long score(long long x)
{
    long long ret=0;

    for(auto k:component)
        ret+=abs(help[k].first*x+help[k].second);

    return ret;
}

void force(double x)
{
    for(auto k:component)
        outp[k]=help[k].first*x+help[k].second;
}
void solve(int node)
{
    component={};

    half_x={};

    dfs(node,1,0);

    if(half_x.size()>1)wrong();

    if(half_x.size()==1)
    {
        double x=*half_x.begin();
        x=x/2;

        force(x);
    }
    else
    {
        set<int> noted={};

        for(auto k:component)
            noted.insert(-help[k].second/help[k].first);

        long long x=0,score_best=1e18;

        for(auto k:noted)
        {
            long long cur=score(k);

            if(score_best>cur)
            {
                x=k;
                score_best=cur;
            }
        }

        force(x);
    }

}
int main()
{
    scanf("%i%i",&n,&m);

    for(int i=1;i<=n;i++)parent[i]=i;

    for(int i=1;i<=m;i++)
    {
        scanf("%i%i%i",&inp[i].u,&inp[i].v,&inp[i].sum);

        adj[inp[i].u].push_back({inp[i].v,inp[i].sum});
        adj[inp[i].v].push_back({inp[i].u,inp[i].sum});

        parent[root(inp[i].u)]=root(inp[i].v);
    }

    for(int i=1;i<=n;i++)
        if(root(i)==i)
        {
            solve(i);
        }

    printf("YES\n");
    for(int i=1;i<=n;i++)
        printf("%.9f ",outp[i]);
    printf("\n");

    return 0;
}