#include <bits/stdc++.h>

using namespace std;

/*
const long long mod = 998244353;
//*
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
/*/
char v[1000003];
struct ura
{
    int a;
    char first,last;
};
ura aint[4000006];
ura join (ura l, ura r)
{
    if(l.a==0)
        return r;
    if(r.a==0)
        return l;
    ura ans;
    if(l.last!=r.first)
    {
        ans.a=l.a+r.a;
        ans.first=l.first;
        ans.last=r.last;
        return ans;
    }
    ans.a=max(l.a-r.a,r.a-l.a);
    if(l.a>r.a)
    {
        ans.first=l.first;
        if(r.a%2==1)
            ans.last='('+'['-l.last;
        else
            ans.last=l.last;
    }
    else
    {
        ans.last=r.last;
        if(l.a%2==1)
            ans.first='('+'['-r.first;
        else
            ans.first=r/*l :( */.first;
    }
    return ans;
}
void build (int nod, int l, int r)
{
    if(r<l)
        return;
    if(l==r)
    {
        aint[nod].a=1;
        aint[nod].first=aint[nod].last=v[l];
        return;
    }
    int mid=(l+r)/2;
    build(nod<<1,l,mid);
    build((nod<<1)|1,mid+1,r);
    aint[nod]=join(aint[nod<<1],aint[(nod<<1)|1]);
}
ura query (int nod, int l, int r, int ql, int qr)
{
    if(ql<=l && r<=qr)
        return aint[nod];
    int mid=(l+r)/2;
    /// l mid | mid+1 r
    ura a,b;
    if(ql<=mid)
        a=query(nod<<1,l,mid,ql,qr);
    if(mid+1<=qr)
        b=query((nod<<1)|1,mid+1,r,ql,qr);
    if(ql<=mid && mid+1<=qr)
        return join(a,b);
    if(ql<=mid)
        return a;
    return b;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);///
    long long n,m,q,t,i,j,k;
    cin>>t;
    while(t--)
    {
        cin>>(v+1);
        n=strlen(v+1);
        for(i=1;i<=n;++i)
        {
          //  cin>>v[i];
            if(v[i]==')')
                v[i]='(';
            if(v[i]==']')
                v[i]='[';
        }
        build(1,1,n);
        cin>>q;
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            ura a=query(1,1,n,l,r);
            cout<<a.a/2<<'\n';
        }
    }
    return 0;
}