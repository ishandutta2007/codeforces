#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 1000000007;

long long lgput (long long a, long long exp)
{
    long long rz=1;
    while(exp)
        if(exp&1)
            exp^=1,rz=rz*1LL*a%mod;
        else
            exp>>=1,a=a*1LL*a%mod;
    return rz;
}
long long fct[200005],invfct[200005],inv[200005];
long long put2[200005];
long long cmb (long long n, long long k)
{
    if(n<k || k<0 || n<0)
        return 0;
    return fct[n]*1LL*invfct[k]%mod*1LL*invfct[n-k]%mod;
}
void init ()
{
    inv[1]=fct[0]=fct[1]=invfct[0]=invfct[1]=put2[0]=1,put2[1]=2;
    for(long long i=2;i<=200000;++i)
        put2[i]=put2[i-1]*2LL%mod,inv[i]=(mod-mod/i)*1LL*inv[mod%i]%mod,fct[i]=i*1LL*fct[i-1]%mod,invfct[i]=inv[i]*1LL*invfct[i-1]%mod;
}
*/
int aint[2000001],v[1000005];
void build (int nod, int l, int r)
{
    if(l==r)
    {
        aint[nod]=v[l];
        return;
    }
    int mid=((l+r)>>1);
    build(nod<<1,l,mid);
    build((nod<<1)|1,mid+1,r);
    aint[nod]=__gcd(aint[nod<<1],aint[(nod<<1)|1]);
}
void upd (int nod, int l, int r, int pz, int val)
{
    if(r<pz || pz<l)
        return;
    if(l==r)
    {
        v[l]=val;
        aint[nod]=v[l];
        return;
    }
    int mid=((l+r)>>1);
    upd(nod<<1,l,mid,pz,val);
    upd((nod<<1)|1,mid+1,r,pz,val);
    aint[nod]=__gcd(aint[nod<<1],aint[(nod<<1)|1]);
}
int qry (int nod, int l, int r, int ql, int qr)
{
    if(ql<=l && r<=qr)
        return aint[nod];
    if(qr<l || r<ql)
        return 0;
    int mid=((l+r)>>1);
    return __gcd(qry(nod<<1,l,mid,ql,qr),qry((nod<<1)|1,mid+1,r,ql,qr));
}
int qry1 (int nod, int l, int r, int ql, int qr, int d)
{
    if(aint[nod]%d==0)
        return 0;
    if(qr<l || r<ql)
        return 0;
    if(ql<=l && r<=qr)
    {
        if(l==r)
            return 1;
        if(aint[nod<<1]%d!=0 && aint[(nod<<1)|1]%d!=0)
            return 2;
        int mid=((l+r)>>1);
        return qry1(nod<<1,l,mid,ql,qr,d)+qry1((nod<<1)|1,mid+1,r,ql,qr,d);
    }
    int mid=((l+r)>>1);
    return qry1(nod<<1,l,mid,ql,qr,d)+qry1((nod<<1)|1,mid+1,r,ql,qr,d);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,q,i,k,m,j=0,n,tt,p,z;
    //cin>>t;
    t=1;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        build(1,1,n);
        cin>>q;
        while(q--)
        {
            int a,b,c,d;
            cin>>a>>b>>c;
            if(a==1)
            {
                cin>>d;
                if(qry1(1,1,n,b,c,d)>=2)
                    cout<<"NO\n";
                else
                    cout<<"YES\n";
            }
            else
            {
                upd(1,1,n,b,c);
            }
        }
    }
    return 0;
}