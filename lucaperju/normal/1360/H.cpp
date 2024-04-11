#include <bits/stdc++.h>

using namespace std;
long long v[103],n,m;
bool check(long long val)
{
    int cnt=0;
    for(int i=1;i<=n;++i)
    {
        if(v[i]==val)
            return false;
        if(v[i]<val)
            ++cnt;
    }
    long long cat=val-cnt+1;
    if(cat==((1LL<<m)-n-1)/2LL+1)
        return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,i,j,k,mx,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        long long val=(1LL<<(m-1));
        for(i=1;i<=n;++i)
            v[i]=0;
        for(i=1;i<=n;++i)
        {
            long long p=(1LL<<(m-1));
            for(j=1;j<=m;++j)
            {
                char c;
                cin>>c;
                if(c=='1')
                    v[i]+=p;
                p>>=1LL;
            }
        }
        for(i=max(0LL,val-101);i<min((1LL<<(m)),val+101);++i)
            if(check(i))
                break;
        long long p=(1LL<<(m-1));
        long long rz=i;
        for(i=1;i<=m;++i)
        {
            if(p&rz)
                cout<<1;
            else
                cout<<0;
            p>>=1;
        }
        cout<<'\n';
    }
    return 0;
}