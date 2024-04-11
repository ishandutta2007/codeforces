//https://codeforces.com/contest/1192/problem/B
//https://codeforces.com/contest/1192/submission/89361255
#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;

int n,q;

int MX;

int cost[nmax];

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
//sum(a)%2=sum(c)%2

struct info
{
    int lazy,a[2],b[2],c[2],ab[2],bc[2],abc[2];
    int flip;
};

info tree[4*nmax];

void push(int node)
{
    tree[node*2].lazy+=tree[node].lazy;
    tree[node*2+1].lazy+=tree[node].lazy;
    tree[node].lazy=0;

    tree[node*2].flip=tree[node*2].flip^tree[node].flip;
    tree[node*2+1].flip=tree[node*2+1].flip^tree[node].flip;
    tree[node].flip=0;
}

info actual(info cur)
{
    cur.a[0]+=cur.lazy;

    cur.a[1]+=cur.lazy;

    cur.b[0]-=2*cur.lazy;

    cur.b[1]-=2*cur.lazy;

    cur.c[0]+=cur.lazy;

    cur.c[1]+=cur.lazy;

    cur.ab[0]-=cur.lazy;

    cur.ab[1]-=cur.lazy;

    cur.bc[0]-=cur.lazy;

    cur.bc[1]-=cur.lazy;

    cur.abc[0]+=0;

    cur.abc[1]+=0;

    cur.lazy=0;

    if(cur.flip)
    {
        cur.flip=0;

        swap(cur.a[0],cur.a[1]);
        swap(cur.b[0],cur.b[1]);
        swap(cur.c[0],cur.c[1]);

        swap(cur.ab[0],cur.ab[1]);
        swap(cur.bc[0],cur.bc[1]);

        swap(cur.abc[0],cur.abc[1]);
    }
    return cur;
}

void print(info cur)
{
    cout<<cur.flip<<" "<<cur.lazy<<" "<<"a: "<<cur.a[0]<<" "<<cur.a[1]<<" b: "<<cur.b[0]<<" "<<cur.b[1]<<" c: "<<cur.c[0]<<" "<<cur.c[1]<<" ab: "<<cur.ab[0]<<" "<<cur.ab[1]
    <<" bc: "<<cur.bc[0]<<" "<<cur.bc[1]<<" abc: "<<cur.abc[0]<<" "<<cur.abc[1]<<endl;
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
    ret.flip=0;

    ret.a[0]=max(l.a[0],r.a[0]);
    ret.a[1]=max(l.a[1],r.a[1]);

    ret.b[0]=max(l.b[0],r.b[0]);
    ret.b[1]=max(l.b[1],r.b[1]);

    ret.c[0]=max(l.c[0],r.c[0]);
    ret.c[1]=max(l.c[1],r.c[1]);

    ret.ab[0]=max(l.ab[0],r.ab[0]);
    ret.ab[0]=max(l.a[0]+max(r.b[0],r.b[1]),ret.ab[0]);

    ret.ab[1]=max(l.ab[1],r.ab[1]);
    ret.ab[1]=max(l.a[1]+max(r.b[0],r.b[1]),ret.ab[1]);

    ret.bc[0]=max(l.bc[0],r.bc[0]);
    ret.bc[0]=max(ret.bc[0],max(l.b[0],l.b[1])+r.c[0]);

    ret.bc[1]=max(l.bc[1],r.bc[1]);
    ret.bc[1]=max(ret.bc[1],max(l.b[0],l.b[1])+r.c[1]);

    ret.abc[0]=max(l.abc[0],r.abc[0]);
    ret.abc[0]=max(l.a[0]+r.bc[0],ret.abc[0]);
    ret.abc[0]=max(l.ab[0]+r.c[0],ret.abc[0]);

    ret.abc[1]=max(l.abc[1],r.abc[1]);
    ret.abc[1]=max(l.a[1]+r.bc[1],ret.abc[1]);
    ret.abc[1]=max(l.ab[1]+r.c[1],ret.abc[1]);

    //cout<<"merged ";print(ret);

    return ret;
}
void update(int node,int l,int r,int lq,int rq,long long diff,bool flip)
{
    if(l==lq&&r==rq)
    {
        tree[node].lazy+=diff;
        tree[node].flip=flip^tree[node].flip;
        return;
    }

    push(node);

    int av=(l+r)/2;

    if(lq<=av)update(node*2,l,av,lq,min(av,rq),diff,flip);
    if(av<rq)update(node*2+1,av+1,r,max(av+1,lq),rq,diff,flip);

    //cout<<"merging "<<node<<" "<<l<<" "<<r<<" "<<av<<endl;

    tree[node]=my_merge(tree[node*2],tree[node*2+1]);
}
void upd(int id,long long cost_new,bool flip)
{
    long long diff=cost_new-cost[id];
    cost[id]=cost_new;

    int lower=edges[id].first,upper=edges[id].second;

    if(in[lower]<=in[upper]&&out[upper]<=out[lower])swap(lower,upper);

    //cout<<"upd "<<id<<" "<<cost_new<<" "<<flip<<endl;
    //cout<<"upd "<<lower<<" "<<diff<<" "<<in[lower]<<" "<<out[lower]<<" "<<flip<<endl;

    update(1,1,2*n-1,in[lower],out[lower],diff,flip);
    /*
    for(int i=1;i<=15;i++)
    {
        cout<<i<<" -> ";print(tree[i]);
        print(actual(tree[i]));
    }
    cout<<"---"<<endl;
    */
}

int type[nmax];
int main()
{
    for(int i=1;i<4*nmax;i++)
    {
        tree[i].a[1]=-1e9;
        tree[i].b[1]=-1e9;
        tree[i].c[1]=-1e9;
        tree[i].ab[1]=-1e9;
        tree[i].bc[1]=-1e9;
        tree[i].abc[1]=-1e9;
    }

    scanf("%i",&n);

    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%i%i%i",&u,&v,&type[i]);

        edges[i]={u,v};

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,0);

    //for(int i=1;i<=n;i++)cout<<i<<" -> "<<in[i]<<" "<<out[i]<<endl;

    //cout<<endl<<"t= "<<t<<endl;

    //for(int i=1;i<=n;i++)cout<<i<<" -> "<<in[i]<<" "<<out[i]<<endl;

    for(int i=1;i<n;i++)
    {
        upd(i,1,type[i]);
    }
    scanf("%i",&q);

    for(int i=1;i<=q;i++)
    {
        int d;

        scanf("%i",&d);

        upd(d,1,1);

        int last=max(actual(tree[1]).abc[0],actual(tree[1]).abc[1]);

        printf("%i\n",last);
    }
    return 0;
}