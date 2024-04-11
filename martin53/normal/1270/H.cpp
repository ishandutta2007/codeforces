#include<bits/stdc++.h>
using namespace std;

const int nmax=5e5+42;

struct info
{
    int lazy,mini,cnt;
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
    cur.mini+=cur.lazy;
    cur.lazy=0;

    return cur;
}

info my_merge(info l,info r)
{
    l=actual(l);
    r=actual(r);

    if(l.mini<r.mini)return l;
    if(l.mini>r.mini)return r;

    l.cnt+=r.cnt;
    return l;
}
void build(int node,int l,int r)
{
    tree[node].cnt=r-l+1;

    if(l==r)return;

    int av=(l+r)/2;

    build(node*2,l,av);
    build(node*2+1,av+1,r);
}
void update(int node,int l,int r,int lq,int rq,int val)
{
    if(l==lq&&r==rq)
    {
        tree[node].lazy+=val;
        return;
    }

    push(node);

    int av=(l+r)/2;

    if(lq<=av)update(node*2,l,av,lq,min(av,rq),val);
    if(av<rq)update(node*2+1,av+1,r,max(av+1,lq),rq,val);

    tree[node]=my_merge(tree[node*2],tree[node*2+1]);
}

set< pair<int,int> > active;
int n,q,inp[nmax];

void block(int l,int r,int val)
{
    if(l>=r)return;

    update(1,1,n,l,r-1,val);
}
void note(int pos,int type)
{
    if(type==1)
    {
        if(active.size()==0)
        {
            active.insert({inp[pos],pos});
            return;
        }

        set< pair<int,int> >::iterator nxt=active.lower_bound({inp[pos],pos});

        set< pair<int,int> >::iterator prv=nxt;prv--;

        if(nxt!=active.end())
        {
            block(pos,(*nxt).second,1);
        }

        if(nxt!=active.begin())
        {
            block((*prv).second,pos,1);
        }

        if(nxt!=active.end()&&nxt!=active.begin())
        {
            block((*prv).second,(*nxt).second,-1);
        }

        active.insert({inp[pos],pos});
    }
    else//type=-1
    {
        active.erase({inp[pos],pos});

        if(active.size()==0)
        {
            return;
        }

        set< pair<int,int> >::iterator nxt=active.lower_bound({inp[pos],pos});

        set< pair<int,int> >::iterator prv=nxt;prv--;

        if(nxt!=active.end())
        {
            block(pos,(*nxt).second,-1);
        }

        if(nxt!=active.begin())
        {
            block((*prv).second,pos,-1);
        }

        if(nxt!=active.end()&&nxt!=active.begin())
        {
            block((*prv).second,(*nxt).second,1);
        }

    }
}
int main()
{
    scanf("%i%i",&n,&q);

    build(1,1,n);

    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);

        note(i,1);
    }

    for(int i=1;i<=q;i++)
    {
        int pos,val;

        scanf("%i%i",&pos,&val);

        note(pos,-1);

        inp[pos]=val;

        note(pos,1);

        printf("%i\n",tree[1].cnt);
    }
    return 0;
}