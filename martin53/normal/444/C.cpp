#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;

struct info
{
    long long add;
    long long sum;
};
info tree[nmax*4];

void compute(int node,int l,int r)
{
    if(l==r)tree[node].sum=tree[node].add;
    else tree[node].sum=tree[node*2].sum+tree[node*2+1].sum+1LL*(r-l+1)*tree[node].add;
}
void push(int node,int l,int r)
{
    tree[node*2].add+=tree[node].add;
    tree[node*2+1].add+=tree[node].add;
    tree[node].add=0;

    int av=(l+r)/2;
    compute(node*2,l,av);
    compute(node*2+1,av+1,r);
    compute(node,l,r);
}

long long query(int node,int l,int r,int lq,int rq)
{
    if(l==lq&&r==rq)return tree[node].sum;
    int av=(l+r)/2;
    long long ret=0;

    push(node,l,r);

    if(lq<=av)ret=ret+query(node*2,l,av,lq,min(av,rq));
    if(av<rq)ret=ret+query(node*2+1,av+1,r,max(av+1,lq),rq);

    compute(node,l,r);
    return ret;
}
void update(int node,int l,int r,int lq,int rq,int add)
{
    if(l==lq&&r==rq)
    {
        //cout<<"updated "<<l<<" "<<r<<" with "<<add<<endl;
        tree[node].add=tree[node].add+add;
        compute(node,l,r);
        return;
    }
    int av=(l+r)/2;
    push(node,l,r);

    if(lq<=av)update(node*2,l,av,lq,min(av,rq),add);
    if(av<rq)update(node*2+1,av+1,r,max(lq,av+1),rq,add);

    compute(node,l,r);
}
int n,m;
set< pair< pair<int/*left*/,int/*right*/>,int/*colour*/> >seen;
int main()
{
scanf("%i%i",&n,&m);
for(int i=1;i<=n;i++){seen.insert({{i,i},i});}
int type,l,r,x;
for(int i=1;i<=m;i++)
{
    scanf("%i%i%i",&type,&l,&r);
    if(type==2)
    {
        printf("%lld\n",query(1,1,n,l,r));
    }
    else
    {
        scanf("%i",&x);
        while(1)
        {
            set< pair< pair<int/*left*/,int/*right*/>,int/*colour*/> >::iterator it=seen.upper_bound({{l,1e9},1e9});
            if(it==seen.end())break;
            pair< pair<int/*left*/,int/*right*/>,int/*colour*/> mem=(*it);
            int le=(*it).first.first;
            int ri=(*it).first.second;
            int val=(*it).second;

            if(r<le)break;

            //cout<<"now "<<le<<" "<<ri<<" "<<val<<endl;

            if(r<ri)
            {
                seen.insert({{r+1,ri},val});
            }
            ri=min(ri,r);
            update(1,1,n,le,ri,abs(val-x));
            seen.erase(mem);
        }

            set< pair< pair<int/*left*/,int/*right*/>,int/*colour*/> >::iterator it=seen.upper_bound({{l,1e9},1e9});
            it--;
            pair< pair<int/*left*/,int/*right*/>,int/*colour*/> mem=(*it);
            int le=(*it).first.first;
            int ri=(*it).first.second;
            int val=(*it).second;

            //cout<<"final now "<<le<<" "<<ri<<" "<<val<<endl;

            if(l<=ri)
            {
                if(r<ri)
                {
                    seen.insert({{r+1,ri},val});
                }
                ri=min(ri,r);

                if(le<l)
                {
                    seen.insert({{le,l-1},val});
                }
                le=max(le,l);

                update(1,1,n,le,ri,abs(val-x));
                seen.erase(mem);
            }
            seen.insert({{l,r},x});
    }
    /*
    cout<<"seen: "<<endl;
    for(auto k:seen)
    {
        if(k.first.first!=k.first.second)cout<<k.first.first<<" "<<k.first.second<<" "<<k.second<<endl;
    }
    */
    /*
    cout<<"tree: "<<endl;
    for(int i=1;i<=5;i++)
    {
        cout<<tree[i].add<<" "<<tree[i].sum<<endl;
    }

    system("pause");
    */
}
return 0;
}