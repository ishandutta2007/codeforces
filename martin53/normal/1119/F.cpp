#include<bits/stdc++.h>
using namespace std;
const int nmax=2.5e5+42;
int n;
vector< pair<int/*to*/,int/*cost*/> > adj[nmax];

vector<int> seen_deg[nmax];

vector< pair<int/*to*/,int/*cost*/> > extra_adj[nmax];

bool on[nmax];

vector<int> starter;

map< pair<int,int>,long long> dp;

int MX;

vector<int> there_active[nmax];

vector< pair<long long/*sum*/,int/*cnt*/> > tree[4*nmax];

void update(int id,int node,int l,int r,int pos,int coeff)
{
    if(l==r)
    {
        tree[id][node].first+=coeff*there_active[id][l];
        tree[id][node].second+=coeff;
        return;
    }

    int av=(l+r)/2;

    if(pos<=av)update(id,node*2,l,av,pos,coeff);
    else update(id,node*2+1,av+1,r,pos,coeff);

    tree[id][node].first=tree[id][node*2].first+tree[id][node*2+1].first;
    tree[id][node].second=tree[id][node*2].second+tree[id][node*2+1].second;
}

void note(int i,int val,int coeff)
{
    //cout<<"note "<<i<<" "<<val<<" "<<coeff<<endl;

    int pos=lower_bound(there_active[i].begin(),there_active[i].end(),val)-there_active[i].begin();

    update(i,1,0,there_active[i].size()-1,pos,coeff);
}

long long query(int id,int node,int l,int r,int to_take)
{
    if(l==r)
    {
        return 1LL*to_take*there_active[id][l];
    }

    int av=(l+r)/2;

    if(tree[id][node*2].second>=to_take)return query(id,node*2,l,av,to_take);
    return tree[id][node*2].first+query(id,node*2+1,av+1,r,to_take-tree[id][node*2].second);
}
long long ask(int node,int to_take)
{
    if(tree[node][1].second<to_take)return 1e12;
    if(to_take==0)return 0;

    return query(node,1,0,there_active[node].size()-1,to_take);
}
long long rec(int node,int parent,bool flag)
{
    if(dp.count({node,flag}))return dp[{node,flag}];

    if(MX==0&&node!=parent&&flag==0)return 1e12;

    int deg=0;

    long long extra=0,ret=1e12;

    vector<long long> help={};

    for(auto k:extra_adj[node])
        if(k.first!=parent)
        {
            extra+=rec(k.first,node,0);//do not use
            help.push_back(rec(k.first,node,1)+k.second-rec(k.first,node,0));
        }

    sort(help.begin(),help.end());

    long long sum_dp=0;

    for(int i=0;i<=help.size();i++)
    {
        long long cur=extra;

        if(i>=1)sum_dp+=help[i-1];

        cur+=sum_dp;

        int remain=adj[node].size()-flag-i;

        remain=remain-MX;

        //cout<<"going "<<node<<" "<<flag<<" "<<i<<" -> "<<cur<<" "<<adj[node].size()<<" "<<flag<<" "<<i<<" "<<MX<<" "<<remain<<endl;

        if(remain>0)
        {
            cur=cur+ask(node,remain);
        }

        ret=min(ret,cur);
    }

    dp[{node,flag}]=ret;

    //cout<<node<<" "<<flag<<" -> "<<ret<<endl;

    return ret;
}

long long outp[nmax];

int main()
{
    scanf("%i",&n);
    int u,v,w;
    for(int i=1;i<n;i++)
    {
        scanf("%i%i%i",&u,&v,&w);
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    for(int i=1;i<=n;i++)
    {
        seen_deg[adj[i].size()].push_back(i);
        for(auto j:adj[i])
            there_active[i].push_back(j.second);
        sort(there_active[i].begin(),there_active[i].end());

        for(int t=0;t<4*there_active[i].size();t++)
        {
            tree[i].push_back({0,0});
        }

        for(auto j:adj[i])
        {
            note(i,j.second,1);
        }
    }

    for(int i=n-1;i>=0;i--)
    {
        for(auto j:seen_deg[i])
        {
            on[j]=1;
            starter.push_back(j);

            for(auto k:adj[j])
            {
                if(on[k.first]==0)
                {
                    /*
                    active[j][k.second]--;
                    active[k.first][k.second]--;
                    */
                }
                else
                {
                    extra_adj[j].push_back(k);
                    extra_adj[k.first].push_back({j,k.second});

                    note(j,k.second,-1);
                    note(k.first,k.second,-1);
                }
            }
        }

        /*
        cout<<"extra: "<<endl;
        for(int i=1;i<=n;i++)
        {
            for(auto j:extra_adj[i])cout<<i<<" "<<j.first<<"\n";
            cout<<endl;
        }
        cout<<"---"<<endl;
        */


        MX=i;

        dp={};
        for(auto cur:starter)
            if(dp.count({cur,0})==0&&dp.count({cur,1})==0)
                outp[i]+=rec(cur,cur,0);

        /*
        cout<<i<<" -> "<<outp[i]<<endl;
        cout<<"---"<<endl;
        */
    }

    for(int i=0;i<n;i++)
        printf("%lld ",outp[i]);

    return 0;
}