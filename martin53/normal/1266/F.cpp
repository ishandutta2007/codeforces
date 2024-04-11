#include<bits/stdc++.h>
using namespace std;

const int nmax=5e5+42;

int outp[nmax];

int n;

vector< pair<int,int> > adj[nmax],mem_adj[nmax];

vector< pair<int,int> > proper_adj[nmax];

vector<int> seen[nmax];

int in=0;

int mem[nmax*2];

vector< pair<int/*size*/,int/*node*/> > there[nmax];

bool cmp(pair<int/*size*/,int/*node*/>a,pair<int/*size*/,int/*node*/>b)
{
    return a>b;
}
void add(int i,pair<int/*size*/,int/*node*/> cur)
{
    there[i].push_back(cur);
    sort(there[i].begin(),there[i].end(),cmp);

    while(there[i].size()>2)there[i].pop_back();
}
int longest(int node,int par,int id)
{
    if(mem[id]!=-1)
    {
        //cout<<"mem "<<id<<" -> "<<mem[id]<<endl;
        return mem[id];
    }
    //cout<<"ask "<<node<<" "<<par<<" "<<id<<endl;

    int ret=0;

    for(auto it:there[node])
        if(it.second!=par)
        {
            ret=max(ret,1+it.first);
            break;
        }

    for(auto k:adj[node])
        if(k.first!=par)
        {
            ret=max(ret,1+longest(k.first,node,k.second));
            //add(node,{longest(k.first,node,k.second),k.first});
        }

    vector< pair<int/*size*/,int/*node*/> > nw={};
    for(auto k:adj[node])
        if(k.first==par)nw.push_back(k);

    adj[node]=nw;

    add(par,{ret,node});

    mem[id]=ret;

    //cout<<node<<" "<<par<<" -> "<<ret<<endl;

    return ret;
}

void solve_odd()
{
    int ret=0;

    for(int i=1;i<=n;i++)
    {
        sort(seen[i].begin(),seen[i].end());

        //cout<<"seen: "<<i<<" -> ";for(auto w:seen[i])cout<<w<<" ";cout<<endl;

        vector<int> there={};
        for(auto k:seen[i])
        {
            //there.push_back(k-1);
            there.push_back(k);
            there.push_back(k+1);
        }

        for(auto now:there)
        {
            int d=now*2-1;

            if(d<=1||d>n)continue;

            int cur=0,extra=0;

            cur=lower_bound(seen[i].begin(),seen[i].end(),now)-seen[i].begin();
            //[cur ... seen[i].size()-1] are valid

            if(cur>=1&&seen[i][cur-1]==(d-1)/2)extra=1;

            cur=1+seen[i].size()-1-cur;

            outp[d]=max(outp[d],cur+extra);
        }
    }
}

void solve_even_1()
{
    for(int i=1;i<=n;i++)
    {
        sort(seen[i].begin(),seen[i].end());

        for(auto now:seen[i])
        {
            int d=2*now;

            if(d>n||d<2)continue;

            int cur=lower_bound(seen[i].begin(),seen[i].end(),now)-seen[i].begin();
            //[cur ... seen[i].size()-1] are valid

            cur=1+seen[i].size()-1-cur;

            outp[d]=max(outp[d],cur);
        }
    }
}

int fenwick[nmax];
void update(int pos,int val)
{
    while(pos<=n)
    {
        fenwick[pos]+=val;
        pos=pos+(pos&(-pos));
    }
}
int query(int pos)
{
    int ret=0;
    while(pos)
    {
        ret+=fenwick[pos];
        pos=pos-(pos&(-pos));
    }
    return ret;
}
int sum(int l,int r)
{
    return query(r)-query(l-1);
}

map<int,int> mem_diff[nmax];

void solve_even_2()
{
    for(int i=1;i<=n;i++)
    {
        for(auto j:proper_adj[i])
            update(j.second+1,1);

        for(auto j:proper_adj[i])
        {
            update(j.second+1,-2);

            vector< pair<int,int> > cur={};
            for(auto q:mem_diff[j.first])
                cur.push_back(q);

            reverse(cur.begin(),cur.end());

            int extra=0;

            for(auto q:cur)
            {
                extra+=q.second;

                int now=q.first+1;

                int d=2*now;

                //cout<<i<<" "<<j<<" "<<now<<" "<<d<<" "<<sum(d/2,n)<<endl;

                if(2<=d&&d<=n)
                {
                    outp[d]=max(outp[d],sum(d/2,n)+extra);
                }
            }

            update(j.second+1,2);
            }

        for(auto j:proper_adj[i])
            update(j.second+1,-1);

        /*
        cout<<"empty? "<<endl;
        for(int j=1;j<=n;j++)
            cout<<sum(j,j)<<" ";
        cout<<endl;
        cout<<endl;
        */
    }
}

void print()
{
    for(int d=n;d>=1;d--)
        outp[d]=max(outp[d],outp[d+2]);

    for(int d=1;d<=n;d++)
        printf("%i ",outp[d]);
}

double T=clock();

int main()
{
    scanf("%i",&n);

    //n=5e5;

    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%i%i",&u,&v);
        /*
        u=1;
        v=i+1;
        */
        adj[u].push_back({v,2*i-1});
        adj[v].push_back({u,2*i});
    }

    for(int i=1;i<=n;i++)
        mem_adj[i]=adj[i];

    for(int i=1;i<=n;i++)outp[i]=1;

    outp[n+1]=1;
    outp[n+2]=1;

    for(int i=1;i<=n;i++)
        if(1+adj[i].size()>outp[1])outp[1]=1+adj[i].size();

    memset(mem,-1,sizeof(mem));

    for(int i=1;i<=n;i++)
        for(auto k:mem_adj[i])
        {
            seen[i].push_back(longest(k.first,i,k.second)+1);

            proper_adj[i].push_back({k.first,seen[i].back()-1});

            mem_diff[i][seen[i].back()-1]++;
        }

    //if(1.0*(clock()-T)/CLOCKS_PER_SEC>2.5)cout<<"slow 202 "<<1.0*(clock()-T)/CLOCKS_PER_SEC<<endl;

    solve_odd();

    //if(1.0*(clock()-T)/CLOCKS_PER_SEC>2.5)cout<<"slow 214 "<<1.0*(clock()-T)/CLOCKS_PER_SEC<<endl;

    solve_even_1();

    //if(1.0*(clock()-T)/CLOCKS_PER_SEC>2.5)cout<<"slow 218 "<<1.0*(clock()-T)/CLOCKS_PER_SEC<<endl;

    solve_even_2();

    //if(1.0*(clock()-T)/CLOCKS_PER_SEC>2.5)cout<<"slow 222 "<<1.0*(clock()-T)/CLOCKS_PER_SEC<<endl;

    //return 0;

    print();

    return 0;
}