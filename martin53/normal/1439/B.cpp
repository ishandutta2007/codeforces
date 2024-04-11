#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,m,k;

set<int> adj[nmax];
int in[nmax];

queue<int> to_remove,idle;

vector<int> to_check[nmax];

bool there(int p,int q)
{
    int pos=lower_bound(to_check[p].begin(),to_check[p].end(),q)-to_check[p].begin();

    if(pos<to_check[p].size()&&to_check[p][pos]==q)return 1;
    return 0;
}

vector< pair<int,int> > busted;

bool check(int node,set<int> cur)
{
    if(in[node]<k-1)return 0;
    for(auto other:cur)
        if(in[other]<k-1)return 0;

    cur.insert(node);

    //for(auto w:cur)cout<<w<<" ";cout<<endl;

    for(auto p:busted)
        if(cur.count(p.first)&&cur.count(p.second))return 0;

    int in=0;

    for(auto p:cur)
        for(auto q:cur)
            if(p<q)
        {
            if(there(p,q)==0||there(q,p)==0)
            {
                if(in>1000)busted.push_back({p,q});

                return 0;
            }

            else in+=2;
        }

    printf("2\n");
    for(auto k:cur)
        printf("%i ",k);
    printf("\n");

    return 1;
}

double T=clock();

void solve()
{
    busted={};

    scanf("%i%i%i",&n,&m,&k);

    for(int i=1;i<=n;i++)adj[i]={},in[i]=0,to_check[i]={};

    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%i%i",&u,&v);
        adj[u].insert(v);
        adj[v].insert(u);

        in[u]++;
        in[v]++;

        to_check[u].push_back(v);
        to_check[v].push_back(u);
    }

    //cout<<1.0*(clock()-T)/CLOCKS_PER_SEC<<endl;

    for(int i=1;i<=n;i++)
        sort(to_check[i].begin(),to_check[i].end());

    to_remove=idle;

    for(int i=1;i<=n;i++)
        if(in[i]<k)
        {
            to_remove.push(i);
            //cout<<"take "<<i<<" "<<in[i]<<endl;
        }

    while(to_remove.size())
    {
        int tp=to_remove.front();

        //cout<<"tp= "<<tp<<" "<<in[tp]<<" "<<adj[tp].size()<<" "<<k<<endl;

        if(in[tp]==k-1)
        {
            if(check(tp,adj[tp]))return;
        }

        to_remove.pop();

        for(auto p:adj[tp])
        {
            in[p]--;

            adj[p].erase(tp);

            if(in[p]==k-1)to_remove.push(p);
        }
    }

    //cout<<busted.size()<<endl;

    vector<int> outp={};

    for(int i=1;i<=n;i++)
        if(adj[i].size()>=k)
            outp.push_back(i);

    if(outp.size())
    {
        printf("1\n");
        printf("%i",outp.size());
        for(auto w:outp)printf(" %i",w);
        printf("\n");
        return;
    }

    printf("-1\n");
}

int main()
{
    //freopen("output.c","r",stdin);

    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;
        solve();
    }
    return 0;
}