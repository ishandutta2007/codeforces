#include <bits/stdc++.h>
using namespace std;
int n,m;
bool queryn (int a, int b, int l)
{
    cout<<"? "<<l<<' '<<m<<' '<<a<<' '<<1<<' '<<b<<' '<<1<<'\n';
    cout.flush();
    int x;
    cin>>x;
    return x;
}
bool verifn (int a, int l)
{
    if(l==2)
        return queryn(1,a/2+1,a/2);
    return (queryn(1,1+(a/l)*(l/2),(a/l)*(l/2))&queryn(1,1+(a/l)*(l/2+1),(a/l)*(l/2)));
}
bool querym (int a, int b, int l)
{
    cout<<"? "<<n<<' '<<l<<' '<<1<<' '<<a<<' '<<1<<' '<<b<<'\n';
    cout.flush();
    int x;
    cin>>x;
    return x;
}
bool verifm (int a, int l)
{
    if(l==2)
        return querym(1,a/2+1,a/2);
    return (querym(1,1+(a/l)*(l/2),(a/l)*(l/2))&querym(1,1+(a/l)*(l/2+1),(a/l)*(l/2)));
}
int main ()
{
    ios_base::sync_with_stdio(0);
    int t,i,q,j,k=0,s=0,mn,mx=0;
    long long rzn=1,rzm=1;
    cin>>n>>m;
    int cn=n;
    for(i=2;i*i<=cn;++i)
    {
        if(cn%i==0)
        {
            int dr=n;
            int cnt=1;
            int ok=1;
            while(cn%i==0)
            {
                if(ok)
                {
                    if(verifn(dr,i))
                        ++cnt;
                    else
                        ok=0;
                }
                cn/=i;
                dr/=i;
            }
            rzn=rzn*1LL*cnt;
        }
    }
    if(cn!=1)
    {
        if(verifn(n,cn))
            rzn=rzn*2LL;
    }
    int cm=m;
    for(i=2;i*i<=cm;++i)
    {
        if(cm%i==0)
        {
            int dr=m;
            int cnt=1;
            int ok=1;
            while(cm%i==0)
            {
                if(ok)
                {
                    if(verifm(dr,i))
                        ++cnt;
                    else
                        ok=0;
                }
                cm/=i;
                dr/=i;
            }
            rzm=rzm*1LL*cnt;
        }
    }
    if(cm!=1)
    {
        if(verifm(m,cm))
            rzm=rzm*2LL;
    }
    cout<<"! "<<rzn*1LL*rzm<<'\n';
    cout.flush();
}