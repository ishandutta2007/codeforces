#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,inp[nmax];

pair<int/*value*/,int/*index*/> arr[nmax];
struct quer
{
    int l,r,d;
};
int q;
quer queries[nmax];
int output[nmax];


struct info
{
    int pref,suff,longest,sz;
};
info tree[4*nmax];

info my_merge(info l,info r)
{
    info ret;
    if(l.sz==l.pref)ret.pref=l.sz+r.pref;
    else ret.pref=l.pref;

    if(r.sz==r.suff)ret.suff=r.sz+l.suff;
    else ret.suff=r.suff;

    ret.longest=max(l.longest,r.longest);
    ret.longest=max(ret.longest,l.suff+r.pref);

    ret.sz=l.sz+r.sz;
    return ret;
}
void build(int node,int l,int r)
{
    if(l==r)
    {
        tree[node].sz=1;
        return;
    }
    int av=(l+r)/2;
    build(node*2,l,av);
    build(node*2+1,av+1,r);

    tree[node]=my_merge(tree[node*2],tree[node*2+1]);
}

void update(int node,int l,int r,int pos,int value)
{
    if(l==r)
    {
        //cout<<pos<<" is "<<value<<" from now"<<endl;
        tree[node].pref=value;
        tree[node].suff=value;
        tree[node].longest=value;
        return;
    }
    int av=(l+r)/2;
    if(pos<=av)update(node*2,l,av,pos,value);
    else update(node*2+1,av+1,r,pos,value);

    tree[node]=my_merge(tree[node*2],tree[node*2+1]);
}
info query(int node,int l,int r,int lq,int rq)
{
    if(l==lq&&r==rq)return tree[node];
    int av=(l+r)/2;
    info ret;ret.longest=0;ret.pref=0;ret.suff=0;ret.sz=0;
    if(lq<=av)ret=my_merge(ret,query(node*2,l,av,lq,min(av,rq)));
    if(av<rq)ret=my_merge(ret,query(node*2+1,av+1,r,max(av+1,lq),rq));
    return ret;
}
void solve(int ok,int not_ok,vector<int> active)
{
    /*
    cout<<"solve: "<<not_ok<<" "<<ok<<endl;
    cout<<"active: ";for(auto k:active)cout<<k<<" ";cout<<endl;
    */
    if(active.size()==0)return;
    if(not_ok-ok==1)
    {
        for(auto k:active)
            output[k]=ok;
        return;
    }

    int av=(ok+not_ok)/2;

    int beg=lower_bound(arr+1,arr+n+1,make_pair(av,0))-arr;
    /*
    cout<<"moment "<<ok<<" "<<av<<" "<<not_ok<<endl;
    cout<<"adding"<<endl;
    */
    for(int i=beg;i<=n&&arr[i].first<not_ok;i++)
        update(1,1,n,arr[i].second,1);

    vector<int> enough={},more={};
    for(auto k:active)
        {
        //cout<<k<<" -> "<<query(1,1,n,queries[k].l,queries[k].r).longest<<endl;
        if(query(1,1,n,queries[k].l,queries[k].r).longest>=queries[k].d)enough.push_back(k);
        else more.push_back(k);
        }
    solve(ok,av,more);
    /*
    cout<<"moment "<<not_ok<<" "<<av<<" "<<ok<<endl;
    cout<<"removing"<<endl;
    */
    for(int i=beg;i<=n&&arr[i].first<not_ok;i++)
        update(1,1,n,arr[i].second,0);

    solve(av,not_ok,enough);
}
int main()
{
scanf("%i",&n);
build(1,1,n);
for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

for(int i=1;i<=n;i++)arr[i]={inp[i],i};
sort(arr+1,arr+n+1);

scanf("%i",&q);

vector<int> active={};
for(int i=1;i<=q;i++)
{
    scanf("%i%i%i",&queries[i].l,&queries[i].r,&queries[i].d);
    active.push_back(i);
}

solve(0,1e9+1,active);

for(int i=1;i<=q;i++)printf("%i\n",output[i]);
return 0;
}