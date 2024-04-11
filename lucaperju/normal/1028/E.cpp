#include <bits/stdc++.h>
using namespace std;
long long v[400005],ok[400005],vf[400005];
int main()
{
    long long n,m,k,i,j,mx=0,s=0;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    for(i=1;i<=n;++i)
        v[i+n]=v[i],s+=v[i];
    int cnt=0;
    v[0]=v[n];
    for(i=1;i<=n+n;++i)
    {
        if(v[i]>v[i-1])
            ok[i]=1,vf[i]=v[i],++cnt;
    }
    if(!cnt)
    {
        if(s==0)
        {
            cout<<"YES\n";
            for(i=1;i<=n;++i)
                cout<<1<<' ';
            return 0;
        }
        cout<<"NO";
        return 0;
    }
    for(i=n+n-1;i>=1;--i)
    {
        if(!ok[i] && ok[i+1])
        {
            ok[i]=1;
            long long b=v[i];
            long long a=v[i-1];
            long long c=vf[i+1];
            long long cat=(a-b)/c-2LL;
            b=max(b,b+cat*1LL*c);
            while(b<=a)
                b+=c;
            vf[i]=b;
        }
    }
    cout<<"YES\n";
    for(i=1;i<=n;++i)
        cout<<vf[i]<<' ';
}