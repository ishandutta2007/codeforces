#include <bits/stdc++.h>

using namespace std;
struct ura
{
    int a,b;
}v[200005];
bool cmp (ura a, ura b)
{
    return a.a>b.a;
}
int main()
{
    ios_base::sync_with_stdio(0);
    long long s,n,q,i,j;
    cin>>q;
    while(q--)
    {
        cin>>n>>s;
        for(i=1;i<=n;++i)
            cin>>v[i].a>>v[i].b;
        sort(v+1,v+n+1,cmp);
        for(i=1;i<=n;++i)
            s-=v[i].a;
        long long k=0,pas=1LL<<33;
        while(pas)
        {
            long long nou=k+pas;
            int cnt=0;
            long long sc=s;
            for(i=1;i<=n;++i)
            {
                if(v[i].b>=nou)
                {
                    if(nou<=v[i].a)
                    {
                        ++cnt;
                    }
                    else if(nou-v[i].a<=sc)
                    {
                        sc-=(nou-v[i].a);
                        ++cnt;
                    }
                }
            }
            if(cnt>=(n+1)/2)
                k=nou;
            pas>>=1LL;
        }
        cout<<k<<'\n';
    }
    return 0;
}