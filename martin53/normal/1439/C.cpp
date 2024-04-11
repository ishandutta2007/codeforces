#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int n,q,inp[nmax];

struct info
{
    long long sum;
    int lazy;
    int cnt;

    int maxi,mini;
};
info tree[4*nmax];

info actual(info cur)
{
    if(cur.lazy)
    {
        cur.sum=1LL*cur.cnt*cur.lazy;
        cur.mini=cur.lazy;
        cur.maxi=cur.lazy;
        cur.lazy=0;
    }
    return cur;
}
info my_merge(info l,info r)
{
    l=actual(l);
    r=actual(r);

    info ret;

    ret.sum=l.sum+r.sum;
    ret.lazy=0;
    ret.cnt=l.cnt+r.cnt;
    ret.maxi=max(l.maxi,r.maxi);
    ret.mini=min(l.mini,r.mini);
    ret.cnt=l.cnt+r.cnt;

    return ret;
}
void push(int node)
{
    if(tree[node].lazy)
    {
        tree[node*2].lazy=tree[node].lazy;
        tree[node*2+1].lazy=tree[node].lazy;
    }
    return;
}
void update(int node,int l,int r,int lq,int rq,int val)
{
    if(l==lq&&r==rq)
    {
        tree[node].cnt=r-l+1;

        tree[node].lazy=val;
        return;
    }

    push(node);

    int av=(l+r)/2;

    if(lq<=av)update(node*2,l,av,lq,min(av,rq),val);
    if(av<rq)update(node*2+1,av+1,r,max(av+1,lq),rq,val);

    tree[node]=my_merge(tree[node*2],tree[node*2+1]);
}

int query(int node,int l,int r,int pos)
{
    if(l==r)return actual(tree[node]).sum;

    push(node);

    int av=(l+r)/2,ret;

    if(pos<=av)ret=query(node*2,l,av,pos);
    else ret=query(node*2+1,av+1,r,pos);

    tree[node]=my_merge(tree[node*2],tree[node*2+1]);

    return ret;
}

int move_nxt(int node,int l,int r,int val)
{
    //cout<<move_nxt<<" "<<node<<" "<<l<<" "<<r<<" "<<val<<" "<<tree[node].lazy<<" "<<tree[node].mini<<endl;

    if(l==r)return l;

    push(node);
    tree[node]=my_merge(tree[node*2],tree[node*2+1]);

    int av=(l+r)/2,ret;

    if(actual(tree[node*2]).mini<=val)ret=move_nxt(node*2,l,av,val);
    else ret=move_nxt(node*2+1,av+1,r,val);

    tree[node]=my_merge(tree[node*2],tree[node*2+1]);

    return ret;
}
int cur_le,cur_sum;

bool move_fast(int node,int l,int r,int lq,int rq)
{
    if(l==lq&&r==rq)
    {
        if(actual(tree[node]).sum<=cur_sum)
        {
            cur_sum=cur_sum-actual(tree[node]).sum;
            cur_le=r+1;
            return 1;
        }

        if(l==r)return 0;
    }

    push(node);

    int av=(l+r)/2;

    if(lq<=av)
    {
        if(move_fast(node*2,l,av,lq,min(av,rq))==0)return 0;
    }

    if(av<rq)
    {
        if(move_fast(node*2+1,av+1,r,max(av+1,lq),rq)==0)return 0;
    }

    return 1;
}
int go(int le,int sum)
{
    //cout<<"go "<<le<<" "<<sum<<endl;

    if(le>n)return 0;

    cur_le=le;
    cur_sum=sum;

    move_fast(1,1,n,le,n);

    int ret=cur_le-le;

    if(cur_le>n)return ret;

    if(cur_sum>=query(1,1,n,n))return go(move_nxt(1,1,n,cur_sum),cur_sum)+ret;

    return ret;
}
int main()
{
    scanf("%i%i",&n,&q);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=1;i<=n;i++)update(1,1,n,i,i,inp[i]);

    for(int i=1;i<=q;i++)
    {
        int type;
        scanf("%i",&type);

        if(type==1)
        {
            int x,val;
            scanf("%i%i",&x,&val);

            if(query(1,1,n,x)>val)continue;

            int ok=move_nxt(1,1,n,val);

            if(ok<=x)update(1,1,n,ok,x,val);
        }
        else
        {
            int le,val;

            scanf("%i%i",&le,&val);

            printf("%i\n",go(le,val));
        }

        //for(int i=1;i<=n;i++)cout<<query(1,1,n,i)<<" ";cout<<endl;
    }

    return 0;
}