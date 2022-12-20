#include<bits/stdc++.h>
using namespace std;

const int nmax=4e5+42;

int n,m,q;

struct info
{
    int min_l,max_r;
    bool found;
};
info tree[4*nmax];
info make_info(int min_l,int max_r,bool found)
{
    info ret;
    ret.min_l=min_l;
    ret.max_r=max_r;
    ret.found=found;
    return ret;
}
info my_merge(info le,info ri)
{
    info ret;

    ret.min_l=min(le.min_l,ri.min_l);
    ret.max_r=max(le.max_r,ri.max_r);

    ret.found=le.found|ri.found;
    ret.found=ret.found|(le.min_l<=ri.max_r);

    return ret;
}
void update(int node,int l,int r,int pos,info cur)
{
    if(l==r)
    {
        tree[node].min_l=min(tree[node].min_l,cur.min_l);
        tree[node].max_r=max(tree[node].max_r,cur.max_r);
        return;
    }

    int av=(l+r)/2;

    if(pos<=av)update(node*2,l,av,pos,cur);
    else update(node*2+1,av+1,r,pos,cur);

    tree[node]=my_merge(tree[node*2],tree[node*2+1]);

    //cout<<node<<" "<<l<<" "<<r<<" "<<tree[node].min_l<<" "<<tree[node].max_r<<" "<<tree[node].found<<endl;
}
int main()
{
    scanf("%i%i%i",&n,&m,&q);
    for(int i=1;i<4*nmax;i++)
        tree[i].min_l=1e9;

    for(int i=1;i<=q;i++)
    {
        int x,y;
        scanf("%i%i",&x,&y);

        if(x%2==1)update(1,1,2*n,x,make_info(y,0,0));
        else update(1,1,2*n,x,make_info(1e9,y,0));

        if(tree[1].found)printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}