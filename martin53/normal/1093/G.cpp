#include<bits/stdc++.h>
using namespace std;
const int nmax=2e5+42;
int n,k;
pair<int/*max*/,int/*min*/> tree[32][4*nmax];
int arr[5];
pair<int/*max*/,int/*min*/> my_merge(pair<int/*max*/,int/*min*/> a,pair<int/*max*/,int/*min*/> b)
{
    return {max(a.first,b.first),min(a.second,b.second)};
}
void update(int ind,int node,int l,int r,int pos,int val)
{
    if(l==r)
    {
        tree[ind][node]={val,val};
        return;
    }
    int av=(l+r)/2;
    if(pos<=av)update(ind,node*2,l,av,pos,val);
    else update(ind,node*2+1,av+1,r,pos,val);
    tree[ind][node]=my_merge(tree[ind][node*2],tree[ind][node*2+1]);
}
pair<int,int> query(int ind,int node,int l,int r,int lq,int rq)
{
    if(l==lq&&r==rq)return tree[ind][node];
    pair<int,int> ret={-1e9,1e9};
    int av=(l+r)/2;
    if(lq<=av)ret=my_merge(ret,query(ind,node*2,l,av,lq,min(rq,av)));
    if(av<rq)ret=my_merge(ret,query(ind,node*2+1,av+1,r,max(av+1,lq),rq));
    return ret;
}
void upd(int pos)
{
    for(int p=0;p<32;p++)
    {
        int s=0;
        for(int j=0;j<5;j++)
            if((p&(1<<j)))s=s+arr[j];
            else s=s-arr[j];
        //cout<<p<<" "<<pos<<" -> "<<s<<endl;
        update(p,1,1,n,pos,s);
    }
}
int main()
{
scanf("%i%i",&n,&k);
for(int i=1;i<=n;i++)
{
    for(int j=0;j<k;j++)
        scanf("%i",&arr[j]);
    upd(i);
}

int type,pos,l,r,q;
scanf("%i",&q);
for(int i=1;i<=q;i++)
{
    scanf("%i",&type);
    if(type==1)
    {
    scanf("%i",&pos);
    for(int j=0;j<k;j++)
        scanf("%i",&arr[j]);
    upd(pos);
    }
    else
    {
        scanf("%i%i",&l,&r);
        int ret=0;
        for(int j=0;j<32;j++)
        {
            pair<int,int> mem=query(j,1,1,n,l,r);
            //cout<<mem.first<<" "<<mem.second<<endl;
            ret=max(ret,mem.first-mem.second);
        }
        printf("%i\n",ret);
    }
}
return 0;
}