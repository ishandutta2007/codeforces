#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42,MX=7;

int n,m,q;

long long inp[nmax];

struct info
{
    int l,r;
    bool flip;
    int last_lose[2][7];//last_lose if last_lost from the previous block is x+difference
};
info tree[4*nmax];

info actual(info cur)
{
    if(cur.flip)
    {
        cur.flip=0;
        for(int i=0;i<MX;i++)
            swap(cur.last_lose[0][i],cur.last_lose[1][i]);
    }
    return cur;
}

info my_merge(info le,info ri)
{
    le=actual(le);
    ri=actual(ri);

    info ret;
    ret.flip=0;
    ret.l=le.l;
    ret.r=ri.r;

    for(int flip=0;flip<2;flip++)
    {
        for(int diff=0;diff<MX;diff++)
        {
            int last_lose=ri.last_lose[flip][diff];

            last_lose=le.last_lose[flip][min(MX-1,last_lose-le.r)];

            ret.last_lose[flip][diff]=last_lose;
        }
    }

    return ret;
}

void push(int node)
{
    tree[node*2].flip=tree[node*2].flip^tree[node].flip;
    tree[node*2+1].flip=tree[node*2+1].flip^tree[node].flip;

    tree[node].flip=0;
}
void build(int node,int l,int r)
{
    if(l==r)
    {
        tree[node].l=l;
        tree[node].r=r;

        for(int flip=0;flip<2;flip++)
            for(int diff=0;diff<MX;diff++)
            {
                int last_lose=l+diff;

                if(last_lose-l<=m);
                else if((inp[l]+flip)%2==1)last_lose=l;
                else ;

                tree[node].last_lose[flip][diff]=last_lose;
            }
        return;
    }

    int av=(l+r)/2;
    build(node*2,l,av);
    build(node*2+1,av+1,r);

    tree[node]=my_merge(tree[node*2],tree[node*2+1]);
}

void update(int node,int l,int r,int lq,int rq)
{
    if(l==lq&&r==rq)
    {
        tree[node].flip=!tree[node].flip;
        return;
    }

    push(node);

    int av=(l+r)/2;

    if(lq<=av)update(node*2,l,av,lq,min(av,rq));
    if(av<rq)update(node*2+1,av+1,r,max(av+1,lq),rq);

    tree[node]=my_merge(tree[node*2],tree[node*2+1]);
}


info query(int node,int l,int r,int lq,int rq)
{
    if(l==lq&&r==rq)return actual(tree[node]);

    push(node);

    int av=(l+r)/2;
    info ret;

    if(rq<=av)ret=query(node*2,l,av,lq,rq);
    else if(av<lq)ret=query(node*2+1,av+1,r,lq,rq);
    else ret=my_merge(query(node*2,l,av,lq,av),query(node*2+1,av+1,r,av+1,rq));

    tree[node]=my_merge(tree[node*2],tree[node*2+1]);
    return ret;
}
int main()
{
    scanf("%i%i%i",&n,&m,&q);

    for(int i=1;i<=n;i++)scanf("%lld",&inp[i]);

    build(1,1,n);

    for(int i=1;i<=q;i++)
    {
        int type;
        scanf("%i",&type);

        if(type==1)
        {
            int l,r;
            long long d;
            scanf("%i%i%lld",&l,&r,&d);

            if(d%2)update(1,1,n,l,r);
        }
        else
        {
            int l,r;

            scanf("%i%i",&l,&r);

            info cur=query(1,1,n,l,r);

            if(cur.last_lose[0][MX-1]==l)printf("2\n");
            else printf("1\n");
        }
    }
    return 0;
}