#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int n,q;

int inp[nmax];

int CNT[nmax];

struct info
{
    int cnt[2];
    int lazy;
};
info tree[4*nmax];

void push(int node)
{
    if(tree[node].lazy!=-1)
    {
        tree[node*2].lazy=tree[node].lazy;
        tree[node*2+1].lazy=tree[node].lazy;
        tree[node].lazy=-1;
    }
}

info actual(info cur)
{
    if(cur.lazy!=-1)
    {
        cur.cnt[cur.lazy]+=cur.cnt[!cur.lazy];
        cur.cnt[!cur.lazy]=0;
        cur.lazy=-1;
    }

    return cur;
}

info my_merge(info a,info b)
{
    a=actual(a);
    b=actual(b);

    a.cnt[0]+=b.cnt[0];
    a.cnt[1]+=b.cnt[1];

    return a;
}

void build(int node,int l,int r)
{
    tree[node].lazy=-1;

    if(l==r)
    {
        tree[node].cnt[CNT[l]]++;
        return;
    }

    int av=(l+r)/2;

    build(node*2,l,av);
    build(node*2+1,av+1,r);

    tree[node].cnt[0]=tree[node*2].cnt[0]+tree[node*2+1].cnt[0];
    tree[node].cnt[1]=tree[node*2].cnt[1]+tree[node*2+1].cnt[1];
}

int query(int node,int l,int r)
{
    if(l==r)return l;

    push(node);

    int av=(l+r)/2,ret=0;

    if(actual(tree[node*2+1]).cnt[1])ret=query(node*2+1,av+1,r);
    else ret=query(node*2,l,av);

    tree[node]=my_merge(tree[node*2],tree[node*2+1]);
    return ret;
}

int ask(int node,int l,int r,int pos)
{
    if(l==r)return actual(tree[node]).cnt[1];

    push(node);

    int av=(l+r)/2,ret=0;

    if(pos<=av)ret=ask(node*2,l,av,pos);
    else ret=ask(node*2+1,av+1,r,pos);

    tree[node]=my_merge(tree[node*2+1],tree[node*2]);

    return ret;
}

void update_forced(int node,int l,int r,int pos,int val)
{
    if(l==r)
    {
        tree[node].lazy=-1;
        tree[node].cnt[0]=0;
        tree[node].cnt[1]=0;
        tree[node].cnt[val]++;

        return;
    }

    push(node);

    int av=(l+r)/2;

    if(pos<=av)update_forced(node*2,l,av,pos,val);
    else update_forced(node*2+1,av+1,r,pos,val);

    tree[node]=my_merge(tree[node*2],tree[node*2+1]);
}

int moved_r=0;

bool update_range(int node,int l,int r,int lq,int rq,int new_value)
{
    if(actual(tree[node]).cnt[new_value]==0&&l==lq&&r==rq)
    {
        tree[node].lazy=new_value;
        moved_r=rq;
        return 1;
    }

    if(l==r)return 0;

    push(node);

    int av=(l+r)/2;

    bool ret=0;

    if(av<lq)
    {
        ret=update_range(node*2+1,av+1,r,lq,rq,new_value);
    }
    else
    {
        if(update_range(node*2,l,av,lq,av,new_value))
            ret=update_range(node*2+1,av+1,r,av+1,rq,new_value);
    }

    tree[node]=my_merge(tree[node*2],tree[node*2+1]);

    return ret;
}

void solve()
{
    scanf("%i%i",&n,&q);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=1;i<=n;i++)CNT[inp[i]]++;

    for(int i=1;i<nmax;i++)
    {
        CNT[i]+=CNT[i-1]/2;
        CNT[i-1]=CNT[i-1]%2;
    }

    build(1,1,nmax-1);

    for(int i=1;i<=q;i++)
    {
        int pos,val;

        scanf("%i%i",&pos,&val);

        moved_r=inp[pos]-1;

        update_range(1,1,nmax-1,inp[pos],nmax-1,1);

        //cout<<"type 1 -> "<<moved_r<<endl;

        update_forced(1,1,nmax-1,moved_r+1,0);

        //cout<<"after removal ";for(int j=1;j<=10;j++)cout<<ask(1,1,nmax-1,j);cout<<endl;

        inp[pos]=val;

        moved_r=inp[pos]-1;

        update_range(1,1,nmax-1,inp[pos],nmax-1,0);

        //cout<<"type 2 -> "<<moved_r<<endl;

        update_forced(1,1,nmax-1,moved_r+1,1);



        //for(int j=1;j<=n;j++)cout<<inp[j]<<" ";cout<<endl;
        //for(int j=1;j<=10;j++)cout<<ask(1,1,nmax-1,j);cout<<endl;

        printf("%i\n",query(1,1,nmax-1));
    }

}

int main()
{
    int t;

    //scanf("%i",&t);

    t=1;

    while(t)
    {
        t--;

        solve();
    }

    return 0;
}