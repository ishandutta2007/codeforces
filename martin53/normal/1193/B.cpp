#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;

pair<int/*day*/,int/*gain*/> inp[nmax];

vector<int> adj[nmax];

int n,m,k;

int SZ[nmax];

void dfs(int node)
{
    SZ[node]=1;

    int which=0;
    for(auto p:adj[node])
    {
        dfs(p);
        SZ[node]+=SZ[p];
        if(SZ[which]<SZ[p])which=p;
    }

}

long long tree[4*nmax];

void push(int node)
{
    tree[node*2]+=tree[node];
    tree[node*2+1]+=tree[node];

    tree[node]=0;
}

set<int> interesting,idle;

void update(int node,int l,int r,int lq,int rq,long long val)
{
    if(l==lq&&r==rq)
    {
        tree[node]+=val;
        return;
    }

    push(node);

    int av=(l+r)/2;

    if(lq<=av)update(node*2,l,av,lq,min(av,rq),val);
    if(av<rq)update(node*2+1,av+1,r,max(av+1,lq),rq,val);
}

long long query(int node,int l,int r,int pos)
{
    if(l==r)return tree[node];

    push(node);

    int av=(l+r)/2;

    if(pos<=av)return query(node*2,l,av,pos);
    return query(node*2+1,av+1,r,pos);
}

void rec(int node)
{
    //cout<<"rec "<<node<<endl;

    vector< pair< pair<int,int>, long long> > to_do={};

    int biggest=0;
    for(auto p:adj[node])
        if(SZ[biggest]<SZ[p])biggest=p;

    for(auto p:adj[node])
        if(p!=biggest)
        {
            rec(p);

            set<int>::iterator it=interesting.begin();

            while((*it)<=k)
            {
                int le=(*it);

                it++;

                int ri=(*it)-1;

                long long val=query(1,1,k,le);

                to_do.push_back({{le,ri},val});
                update(1,1,k,le,ri,-val);
            }

            interesting=idle;
        }

    if(biggest)rec(biggest);

    for(auto cur:to_do)
    {
        update(1,1,k,cur.first.first,cur.first.second,cur.second);
        interesting.insert(cur.first.first);
    }

    if(inp[node].first)
    {
        interesting.insert(inp[node].first);
        interesting.insert(inp[node].first+1);

        update(1,1,k,inp[node].first,inp[node].first,inp[node].second);

        //cout<<"before: ";for(int i=1;i<=k;i++)cout<<query(1,1,k,i)<<" ";cout<<endl;

        long long fixed_value=query(1,1,k,inp[node].first);

        //cout<<"fixed= "<<fixed_value<<endl;

        while(1)
        {
            set<int>::iterator it=interesting.upper_bound(inp[node].first);

            int le=*it;

            //cout<<"trying to make better le= "<<le<<endl;

            if(le>k)break;

            long long val=query(1,1,k,le);

            //cout<<"val= "<<val<<endl;

            if(val>fixed_value)break;

            it++;

            int ri=(*it)-1;

            //cout<<"ri= "<<ri<<" with "<<fixed_value-val<<endl;

            update(1,1,k,le,ri,fixed_value-val);

            interesting.erase(le);
        }
    }
    /*
    cout<<"finished "<<node<<endl;

    cout<<"interesting ";for(auto w:interesting)cout<<w<<" ";cout<<endl;

    cout<<"tree ";for(int i=1;i<=k;i++)cout<<query(1,1,k,i)<<" ";cout<<endl;

    cout<<"---"<<endl;
    */
}
int main()
{
    scanf("%i%i%i",&n,&m,&k);

    interesting.insert(1);
    interesting.insert(k+1);

    idle=interesting;

    for(int i=2;i<=n;i++)
    {
        int p;
        scanf("%i",&p);
        adj[p].push_back(i);
    }

    dfs(1);

    for(int i=1;i<=m;i++)
    {
        int v,d,w;
        scanf("%i%i%i",&v,&d,&w);
        inp[v]={d,w};
    }

    rec(1);

    printf("%lld\n",query(1,1,k,k));
    return 0;
}