#include<bits/stdc++.h>
using namespace std;
const int nmax=2e5+42;

int n,q;

long long MX;

long long cost[nmax];

int SZ[nmax];

vector< int > adj[nmax];

pair<int,int> edges[nmax];

int in[nmax],out[nmax],t;

void dfs(int node,int par)
{
    t++;

    //cout<<node<<" ";

    in[node]=t;

    for(auto k:adj[node])
        if(k!=par)
        {
            dfs(k,node);
            t++;

            //cout<<node<<" ";
        }
    out[node]=t;
}

//max depth[a]-2*depth[b]+depth[c], a<=b<=c

struct info
{
    long long lazy,a,b,c,ab,bc,abc;
};

info tree[4*nmax];

void push(int node)
{
    tree[node*2].lazy+=tree[node].lazy;
    tree[node*2+1].lazy+=tree[node].lazy;
    tree[node].lazy=0;
}

info actual(info cur)
{
    cur.a+=cur.lazy;

    cur.b-=2*cur.lazy;

    cur.c+=cur.lazy;

    cur.ab-=cur.lazy;

    cur.bc-=cur.lazy;

    cur.abc+=0;

    cur.lazy=0;

    return cur;
}

void print(info cur)
{
    cout<<cur.lazy<<" "<<cur.a<<" "<<cur.b<<" "<<cur.c<<" "<<cur.ab<<" "<<cur.bc<<" "<<cur.abc<<endl;
}

info my_merge(info l,info r)
{
    //print(l);
    //print(r);

    l=actual(l);
    r=actual(r);

    //cout<<"into ";print(l);
    //cout<<"into ";print(r);

    info ret;
    ret.lazy=0;

    ret.a=max(l.a,r.a);

    ret.b=max(l.b,r.b);

    ret.c=max(l.c,r.c);

    ret.ab=max(l.ab,r.ab);
    ret.ab=max(l.a+r.b,ret.ab);

    ret.bc=max(l.bc,r.bc);
    ret.bc=max(ret.bc,l.b+r.c);

    ret.abc=max(l.abc,r.abc);
    ret.abc=max(l.a+r.bc,ret.abc);
    ret.abc=max(l.ab+r.c,ret.abc);

    //cout<<"merged ";print(ret);

    return ret;
}
void update(int node,int l,int r,int lq,int rq,long long diff)
{
    if(l==lq&&r==rq)
    {
        tree[node].lazy+=diff;
        return;
    }

    push(node);

    int av=(l+r)/2;

    if(lq<=av)update(node*2,l,av,lq,min(av,rq),diff);
    if(av<rq)update(node*2+1,av+1,r,max(av+1,lq),rq,diff);

    //cout<<"merging "<<node<<" "<<l<<" "<<r<<" "<<av<<endl;

    tree[node]=my_merge(tree[node*2],tree[node*2+1]);
}
void upd(int id,long long cost_new)
{
    long long diff=cost_new-cost[id];
    cost[id]=cost_new;

    int lower=edges[id].first,upper=edges[id].second;

    if(in[lower]<=in[upper]&&out[upper]<=out[lower])swap(lower,upper);

    //cout<<"upd "<<lower<<" "<<diff<<" "<<in[lower]<<" "<<out[lower]<<endl;

    update(1,1,2*n-1,in[lower],out[lower],diff);
    /*
    for(int i=1;i<=15;i++)
    {
        cout<<i<<" -> ";print(tree[i]);
        print(actual(tree[i]));
    }

    cout<<"---"<<endl;
    */
}
int main()
{
    scanf("%i%i%lld",&n,&q,&MX);

    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%i%i%lld",&u,&v,&cost[i]);

        edges[i]={u,v};

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,0);

    //cout<<endl<<"t= "<<t<<endl;

    //for(int i=1;i<=n;i++)cout<<i<<" -> "<<in[i]<<" "<<out[i]<<endl;

    for(int i=1;i<n;i++)
    {
        long long mem=cost[i];
        cost[i]=0;
        upd(i,mem);
    }

    long long last=0;

    //printf("%lld\n",actual(tree[1]).abc);

    for(int i=1;i<=q;i++)
    {
        long long d,e;

        scanf("%lld%lld",&d,&e);

        d=(d+last)%(n-1);

        e=(e+last)%MX;

        upd(d+1,e);

        last=actual(tree[1]).abc;

        printf("%lld\n",last);
    }
    return 0;
}