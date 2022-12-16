#include<bits/stdc++.h>
using namespace std;

const int nmax=5e5+42;
const long long inf=1e18;

int n,q;

vector<int> seen[nmax];

int table[3][nmax];

long long pref[3][nmax];

struct query
{
    int l,r;
    long long cost;
};

query inp[nmax];

long long dp[nmax];

bool cmp(query a,query b)
{
    return a.r<b.r;
}

long long LHS[nmax],RHS[nmax];

struct info
{
    long long LHS,RHS;
    long long MX;
};

info tree[4*nmax];

info my_merge(info a,info b)
{
    info ret;
    ret.LHS=max(a.LHS,b.LHS);
    ret.RHS=max(a.RHS,b.RHS);

    ret.MX=max(max(a.MX,b.MX),a.LHS+b.RHS);
    return ret;
}

void build(int node,int l,int r)
{
    if(l==r)
    {
        tree[node].LHS=LHS[l];
        tree[node].RHS=RHS[r];
        tree[node].MX=tree[node].LHS+tree[node].RHS;
        return;
    }

    int av=(l+r)/2;

    build(node*2,l,av);
    build(node*2+1,av+1,r);

    tree[node]=my_merge(tree[node*2],tree[node*2+1]);
}

info query(int node,int l,int r,int lq,int rq)
{
    if(l==lq&&r==rq)return tree[node];

    int av=(l+r)/2;

    if(rq<=av)return query(node*2,l,av,lq,rq);
    if(av<lq)return query(node*2+1,av+1,r,lq,rq);

    return my_merge(query(node*2,l,av,lq,av),query(node*2+1,av+1,r,av+1,rq));
}

long long tree_MX[4*nmax];

void build_2(int node,int l,int r)
{
    if(l==r)
    {
        tree_MX[node]=-pref[1][l-1]+max(dp[l],pref[0][l]);
        return;
    }

    int av=(l+r)/2;

    build_2(node*2,l,av);
    build_2(node*2+1,av+1,r);

    tree_MX[node]=max(tree_MX[node*2],tree_MX[node*2+1]);
}

long long query_MX(int node,int l,int r,int lq,int rq)
{
    if(l==lq&&r==rq)return tree_MX[node];

    int av=(l+r)/2;

    long long ret=-inf;

    if(lq<=av)ret=max(ret,query_MX(node*2,l,av,lq,min(av,rq)));
    if(av<rq)ret=max(ret,query_MX(node*2+1,av+1,r,max(av+1,lq),rq));

    return ret;
}

void update_MX(int node,int l,int r,int pos)
{
    if(l==r)
    {
        tree_MX[node]=-pref[1][l-1]+max(dp[l],pref[0][l]);
        return;
    }

    int av=(l+r)/2;

    if(pos<=av)update_MX(node*2,l,av,pos);
    else update_MX(node*2+1,av+1,r,pos);

    tree_MX[node]=max(tree_MX[node*2],tree_MX[node*2+1]);
}

int main()
{
    scanf("%i%i",&n,&q);

    for(int t=0;t<3;t++)
    {
        for(int i=1;i<=n;i++)scanf("%i",&table[t][i]);

        for(int i=1;i<=n;i++)pref[t][i]=pref[t][i-1]+table[t][i];
    }

    for(int i=1;i<=q;i++)
    {
        scanf("%i%i%lld",&inp[i].l,&inp[i].r,&inp[i].cost);
    }

    for(int i=0;i<=n+1;i++)dp[i]=-inf;

    sort(inp+1,inp+q+1,cmp);

    build_2(1,1,n);

    for(int j=1;j<=q;j++)
    {
        if(inp[j].r==n)continue;

        dp[inp[j].r+1]=max(dp[inp[j].r+1],query_MX(1,1,n,inp[j].l,inp[j].r)+pref[1][inp[j].r]-inp[j].cost);

        update_MX(1,1,n,inp[j].r+1);

        /*
        int r=inp[j].r+1;

        for(int l=inp[j].l;l<=inp[j].r;l++)
        {
            dp[r]=max(dp[r],pref[1][r-1]-pref[1][l-1]+max(dp[l],pref[0][l])-inp[j].cost);
        }

        */
    }

    for(int l=1;l<=n;l++)
        dp[l]=max(dp[l],pref[0][l]);

    for(int l=1;l<=n;l++)
        LHS[l]=dp[l]-pref[1][l-1];

    for(int r=1;r<=n;r++)
        RHS[r]=pref[1][r]+pref[2][n]-pref[2][r-1];

    build(1,1,n);

    long long outp=-inf;

    for(int j=1;j<=q;j++)
    {
        outp=max(outp,query(1,1,n,inp[j].l,inp[j].r).MX-inp[j].cost);
    }

    printf("%lld\n",outp);

    return 0;
}