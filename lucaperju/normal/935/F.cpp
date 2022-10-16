#include <bits/stdc++.h>

using namespace std;
long long v[100003];
long long dif[100003];
struct tip
{
    long long fel,a,b; /// 1 = varf | 2 = vale | 3 = panta
};
tip gettip (long long pz)
{
    long long d1=dif[pz-1];
    long long d2=dif[pz];
    tip a={0,0,0};
    if(d1<=0 && d2>=0)
        a.fel=1;
    else if(d1>0 && d2<0)
    {
        a.fel=2;
        a.a=min(d1,-d2);
        a.b=max(d1,-d2);
    }
    else
    {
        a.fel=3;
        a.a=max(d1,-d2);
    }
    return a;
}
struct ura
{
    long long fv,av,bv;
    long long ap;
}aint[400003];
ura join (ura a, ura b)
{
    ura rz={0,0,0,0};
    if(a.ap==0)
        rz.ap=b.ap;
    else if(b.ap==0)
        rz.ap=a.ap;
    else
        rz.ap=min(a.ap,b.ap);
    if(b.fv==1 || a.fv==0)
        swap(a,b);
    rz.fv=a.fv;
    rz.av=a.av;
    rz.bv=a.bv;
    return rz;
}
ura tipToUra (tip a)
{
    ura b={0,0,0,0};
    if(a.fel==1)
        b.fv=1;
    else if(a.fel==2)
        b.fv=2,b.av=a.a,b.bv=a.b;
    else if(a.fel==3)
        b.ap=a.a;
    return b;
}
void upd (long long nod, long long st, long long dr, long long pz, tip a)
{
    if(st==dr)
    {
        aint[nod]=tipToUra(a);
        return;
    }
    long long mid=(st+dr)/2;
    if(pz<=mid)
        upd(nod<<1,st,mid,pz,a);
    else
        upd((nod<<1)|1,mid+1,dr,pz,a);
    aint[nod]=join(aint[nod<<1],aint[(nod<<1)|1]);
}
ura query (long long nod, long long st, long long dr, long long ql, long long qr)
{
    if(ql<=st && dr<=qr)
        return aint[nod];
    long long mid=(st+dr)/2;
    ura a={0,0,0,0};
    if(ql<=mid)
        a=query(nod<<1,st,mid,ql,qr);
    if(mid<qr)
        a=join(a,query((nod<<1)|1,mid+1,dr,ql,qr));
    return a;
}
long long getadd (ura a, long long x)
{
    long long mx=-2LL*x;
    if(a.fv==1)
        return x*2LL;
    if(a.ap!=0)
        mx=max(mx,max(0LL,x-a.ap)*2LL);
    if(a.fv!=0)
        mx=max(mx,-a.av*2LL+max(0LL,x-a.bv)*2LL);
    return mx;
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long n,i,j,q;
    long long s=0;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    for(i=1;i<n;++i)
    {
        dif[i]=v[i]-v[i+1];
        s+=max(dif[i],-dif[i]);
    }
    for(i=2;i<n;++i)
    {
        tip a=gettip(i);
        upd(1,2,n-1,i,a);
    }
    cin>>q;
    while(q--)
    {
        long long a,l,r,x;
        cin>>a>>l>>r>>x;
        if(a==1)
        {
            ura aa=query(1,2,n-1,l,r);
            cout<<s+getadd(aa,x)<<'\n';
        }
        else
        {
            s-=max(dif[l-1],-dif[l-1]);
            s-=max(dif[r],-dif[r]);
            dif[l-1]-=x;
            dif[r]+=x;
            s+=max(dif[l-1],-dif[l-1]);
            s+=max(dif[r],-dif[r]);
            if(l-1>1)
            upd(1,2,n-1,l-1,gettip(l-1));
            upd(1,2,n-1,l,gettip(l));
            upd(1,2,n-1,r,gettip(r));
            if(r+1<n)
            upd(1,2,n-1,r+1,gettip(r+1));
        }
    }
	return 0;
}