#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42,lim=18;
struct my_node
{
long long l,r,ans;
bool whole;
};
my_node tree[20][4*nmax];
int n;
int arr[nmax];
my_node my_merge(my_node l,my_node r)
{
    my_node ret;
    ret.whole=(l.whole&&r.whole);
    ret.ans=(l.ans+r.ans+l.r*r.l);
    if(l.whole)ret.l=l.l+r.l;
    else ret.l=l.l;
    if(r.whole)ret.r=l.r+r.r;
    else ret.r=r.r;
    return ret;
}
void update(int ind,int node,int l,int r,int pos)
{
    if(l==r)
    {
        tree[ind][node].l=((arr[l]>>ind)&1);
        tree[ind][node].r=((arr[l]>>ind)&1);
        tree[ind][node].ans=((arr[l]>>ind)&1);
        tree[ind][node].whole=((arr[l]>>ind)&1);
        //cout<<ind<<" "<<node<<" is "<<((arr[l]>>ind)&1)<<endl;
        return;
    }
    int av=(l+r)/2;
    if(pos<=av)update(ind,node*2,l,av,pos);
    else update(ind,node*2+1,av+1,r,pos);
    tree[ind][node]=my_merge(tree[ind][node*2],tree[ind][node*2+1]);
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cout.tie();

int m,v,p;
cin>>n>>m;
for(int i=1;i<=n;i++)
{
cin>>arr[i];
    for(int j=0;j<lim;j++)
        update(j,1,1,n,i);
}
for(int i=1;i<=m;i++)
{
    cin>>p>>v;
    arr[p]=v;
    for(int j=0;j<lim;j++)
        update(j,1,1,n,p);
    long long ans=0;
    for(int j=0;j<lim;j++)
        {
        //cout<<j<<" -> "<<tree[j][1].ans<<endl;
        ans=ans+(tree[j][1].ans<<j);
        }
    cout<<ans<<endl;
}
return 0;
}