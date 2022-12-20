#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int n,q;

char inp[nmax];

//max depth(a)-2*depth(b)+depth(c)
//a<=b<=c
struct info
{
    int lazy;
    int a,b,c,ab,bc,abc;
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
info my_merge(info l,info r)
{
    l=actual(l);
    r=actual(r);

    info ret;

    ret.lazy=0;

    ret.a=max(l.a,r.a);
    ret.b=max(l.b,r.b);
    ret.c=max(l.c,r.c);

    ret.ab=max(l.ab,r.ab);
    ret.ab=max(ret.ab,l.a+r.b);

    ret.bc=max(l.bc,r.bc);
    ret.bc=max(ret.bc,l.b+r.c);

    ret.abc=max(l.abc,r.abc);
    ret.abc=max(ret.abc,max(l.a+r.bc,l.ab+r.c));

    return ret;
}
void update(int node,int l,int r,int lq,int rq,int type)
{
    if(l==lq&&r==rq)
    {
        if(type==1)tree[node].lazy++;
        else tree[node].lazy--;
        return;
    }

    push(node);

    int av=(l+r)/2;

    if(lq<=av)update(node*2,l,av,lq,min(av,rq),type);
    if(av<rq)update(node*2+1,av+1,r,max(av+1,lq),rq,type);

    tree[node]=my_merge(tree[node*2],tree[node*2+1]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    cin>>n>>q;

    n=2*(n-1);

    for(int i=1;i<=n;i++)
    {
        cin>>inp[i];
        update(1,1,n,i,n,(inp[i]=='('));
    }

    cout<<actual(tree[1]).abc<<"\n";

    for(int i=1;i<=q;i++)
    {
        int x,y;

        cin>>x>>y;

        if(x!=y)
        {
            update(1,1,n,x,n,!(inp[x]=='('));
            update(1,1,n,y,n,!(inp[y]=='('));

            swap(inp[x],inp[y]);

            update(1,1,n,x,n,(inp[x]=='('));
            update(1,1,n,y,n,(inp[y]=='('));
        }

        cout<<actual(tree[1]).abc<<"\n";
    }
    return 0;
}