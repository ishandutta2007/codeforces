#include<bits/stdc++.h>
using namespace std;
const int nmax=3e5+42;
int n,arr[nmax];
pair<int/*value*/,int/*index*/> tree[4*nmax];
void build(int node,int l,int r)
{
    if(l==r)
    {
        tree[node]={arr[l],l};
        return;
    }
    int av=(l+r)/2;
    build(node*2,l,av);
    build(node*2+1,av+1,r);
    tree[node]=max(tree[node*2],tree[node*2+1]);
}

pair<int/*value*/,int/*index*/> query(int node,int l,int r,int lq,int rq)
{
    if(l==lq&&r==rq)return tree[node];
    int av=(l+r)/2;
    pair<int/*value*/,int/*index*/> ret={0,0};
    if(lq<=av)ret=max(ret,query(node*2,l,av,lq,min(av,rq)));
    if(av<rq)ret=max(ret,query(node*2+1,av+1,r,max(av+1,lq),rq));
    return ret;
}

int previous[nmax];
int seen[nmax];

int sparse[20][nmax];

int mem_log[nmax];

void prec()
{
    for(int i=1;i<=n;i++)
        sparse[0][i]=previous[i];

    for(int d=1;(1<<d)<=n;d++)
        for(int i=1;i+(1<<d)-1<=n;i++)
        sparse[d][i]=max(sparse[d-1][i],sparse[d-1][i+(1<<(d-1))]);

    for(int i=2;i<=n;i++)
    {
        mem_log[i]=mem_log[i-1];
        if((1<<(mem_log[i]+1))<=i)mem_log[i]++;
    }

}
int ask(int l,int r)//ask if max(previous[l]...previous[r])<l
{
    int s=mem_log[r-l+1];

    return max(sparse[s][l],sparse[s][r+1-(1<<s)])<l;
}
int solve(int l,int r)
{
    if(l>r)return 0;

    int mx=query(1,1,n,l,r).second;

    int ret=solve(l,mx-1);

    ret=ret+solve(mx+1,r);

    int p,q;
    if(r-mx+1<=mx-l+1)
    {
        for(q=mx;q<=r;q++)
        {
            p=q+1-arr[mx];
            if(l<=p&&p<=mx)
                ret=ret+ask(p,q);
        }
    }
    else//r-mx+1>mx-l+1
    {
        for(p=l;p<=mx;p++)
        {
            q=p+arr[mx]-1;
            if(mx<=q&&q<=r)
                ret=ret+ask(p,q);
        }
    }
    return ret;
}
int main()
{
scanf("%i",&n);
for(int i=1;i<=n;i++)scanf("%i",&arr[i]);

for(int i=1;i<=n;i++)
{
    previous[i]=seen[arr[i]];
    seen[arr[i]]=i;
}
build(1,1,n);

prec();

cout<<solve(1,n)<<endl;
return 0;
}