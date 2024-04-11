#include <bits/stdc++.h>
using namespace std;

struct ura
{
    int cnt;
    int v[41];
}aint[400005];
ura nmk;
int v[100005];
ura join (ura a, ura b)
{
    ura ans;
    ans.cnt=min(40,a.cnt+b.cnt);
    int x=1,y=1;
    for(int i=1;i<=ans.cnt;++i)
    {
        if(x>a.cnt)
            ans.v[i]=b.v[y++];
        else if(y>b.cnt || a.v[x]<b.v[y])
            ans.v[i]=a.v[x++];
        else if(b.v[y]<=a.v[x])
            ans.v[i]=b.v[y++];
    }
    return ans;
}
void build (int nod, int l, int r)
{
    if(l==r)
    {
        aint[nod].cnt=1;
        aint[nod].v[1]=v[l];
        return;
    }
    int mid=(l+r)>>1;
    build(nod<<1,l,mid);
    build((nod<<1)|1,mid+1,r);
    aint[nod]=join(aint[nod<<1],aint[(nod<<1)|1]);
}
ura qry (int nod, int l, int r, int ql, int qr)
{
    if(ql<=l && r<=qr)
        return aint[nod];
    if(r<ql || qr<l)
        return nmk;
    int mid=(l+r)>>1;
    return join(qry(nod<<1,l,mid,ql,qr),qry((nod<<1)|1,mid+1,r,ql,qr));
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n,i,j,t;
    cin>>t;
    nmk.cnt=0;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        build(1,1,n);
        int q;
        cin>>q;
        while(q--)
        {
            int a,b;
            cin>>a>>b;
            ura x=qry(1,1,n,a,b);
            int ans=(x.v[1]|x.v[2]);
            for(i=1;i<=x.cnt;++i)
                for(j=i+1;j<=x.cnt;++j)
                    ans=min(ans,x.v[i]|x.v[j]);
            cout<<ans<<'\n';
        }
    }
}