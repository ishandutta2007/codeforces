#include <bits/stdc++.h>

using namespace std;
const int mod=1000000007;
long long lgput (long long a, long long exp)
{
    long long rz=1;
    while(exp)
    {
        if(exp&1LL)
        {
            rz=(rz*1LL*a)%mod;
            --exp;
        }
        else
        {
            a=(a*1LL*a)%mod;
            exp>>=1LL;
        }
    }
    return rz;
}
int v[1000006];
int st[1000006];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long m,n,k,t,i,j,mx,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0;
    cin>>t;
    while(t--)
    {
        k=0;
        cin>>n>>p;
        for(i=1;i<=n;++i)
            cin>>v[i];
        if(p==1)
        {
            if(n%2==0)
                cout<<"0\n";
            else
                cout<<"1\n";
            continue;
        }
        sort(v+1,v+n+1);
        k=0;
        for(i=n;i>=1;--i)
        {
            if(k && st[1]>0)
            {
                // bag negativ
                st[++k]=-(v[i]+1);
                while(k>=2 && st[k]+st[k-1]==0)
                    k-=2;
                while(k>=p && st[k]==st[k-p+1])
                {
                    k=k-p+1;
                    if(st[k]>0)
                        ++st[k];
                    else
                        --st[k];
                    while(k>=2 && st[k]+st[k-1]==0)
                        k-=2;
                }
            }
            else
            {
                // bag pozitiv
                st[++k]=v[i]+1;
                while(k>=2 && st[k]+st[k-1]==0)
                    k-=2;
                while(k>=p && st[k]==st[k-p+1])
                {
                    k=k-p+1;
                    if(st[k]>0)
                        ++st[k];
                    else
                        --st[k];
                    while(k>=2 && st[k]+st[k-1]==0)
                        k-=2;
                }
            }
        }
        long long s=0;
        if(st[1]<0)
        {
            for(i=1;i<=k;++i)
                st[i]=-st[i];
        }
        for(i=1;i<=k;++i)
        {
            if(st[i]>0)
                s=(s+lgput(p,st[i]-1))%mod;
            else
                s=(s+mod-lgput(p,-1-st[i]))%mod;
        }
        cout<<s<<'\n';
    }
    return 0;
}