#include<bits/stdc++.h>
#define int long long
using namespace std;
char my_get_char()
{
    char x;
    scanf("%c",&x);
    while(x!='+'&&x!='-'&&x!='?')scanf("%c",&x);
    return x;
}
const int nmax=3e5+42,LIM=1<<21,MX=1e6;
struct info
{
    int mx;
    int power;
};
info my_merge(info le,info ri)
{
    info ret;
    ret.power=le.power+ri.power;
    ret.mx=max(le.mx+ri.power,ri.mx);
    return ret;
};
info tree[LIM];
void build(int node,int l,int r)
{
    if(l==r)
    {
        tree[node].mx=l;
        return;
    }
    int av=(l+r)/2;
    build(node*2,l,av);
    build(node*2+1,av+1,r);
    tree[node].mx=max(tree[node*2].mx,tree[node*2+1].mx);
}
struct operation
{
    char type;
    int pos,dur;
};
operation inp[nmax];
int q;
void update(int node,int l,int r,int pos,int duration)
{
    //cout<<"   update "<<node<<" "<<l<<" "<<r<<" "<<pos<<" "<<duration<<endl;
    if(l==r)
    {
        tree[node].power+=duration;
        tree[node].mx+=duration;
        //cout<<"\t node "<<node<<" with "<<l<<" "<<r<<" is now "<<tree[node]<<endl;
        return;
    }
    int av=(l+r)/2;
    if(pos<=av)update(node*2,l,av,pos,duration);
    else update(node*2+1,av+1,r,pos,duration);

    tree[node]=my_merge(tree[node*2],tree[node*2+1]);
}
info query(int node,int l,int r,int lq,int rq)
{
    //cout<<"query "<<node<<" "<<l<<" "<<r<<" "<<lq<<" "<<rq<<" "<<tree[node]<<endl;
    if(l==lq&&r==rq)return tree[node];
    int av=(l+r)/2;
    info ret;ret.mx=0;ret.power=0;
    if(lq<=av)ret=my_merge(ret,query(node*2,l,av,lq,min(av,rq)));
    if(av<rq)ret=my_merge(ret,query(node*2+1,av+1,r,max(av+1,lq),rq));
    return ret;
}
signed main()
{
build(1,1,MX);
scanf("%lld",&q);
for(int i=1;i<=q;i++)
{
    inp[i].type=my_get_char();
    scanf("%i",&inp[i].pos);
    if(inp[i].type=='+')
    {
        scanf("%lld",&inp[i].dur);
        update(1,1,MX,inp[i].pos,inp[i].dur);
    }
    if(inp[i].type=='-')
    {
        update(1,1,MX,inp[inp[i].pos].pos,-inp[inp[i].pos].dur);
    }
    if(inp[i].type=='?')
    {
        printf("%lld\n",query(1,1,MX,1,inp[i].pos).mx-inp[i].pos);
    }
    //cout<<inp[i].type<<" "<<inp[i].pos<<" "<<inp[i].dur<<endl;
}

return 0;
}