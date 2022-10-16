#include <bits/stdc++.h>

using namespace std;
char v[1003];
int st0[1003],dr0[1003],st1[1003],dr1[1003];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,k,t,i,j,mx,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0;
    cin>>t;
    while(t--)
    {
        cin>>(v+1);
        n=strlen(v+1);
        for(i=0;i<=n+1;++i)
            st0[i]=dr0[i]=dr1[i]=st1[i]=0;
        for(i=1;i<=n;++i)
        {
            st0[i]=st0[i-1]+1-(v[i]-'0');
            st1[i]=st1[i-1]+v[i]-'0';
        }
        for(i=n;i>=1;--i)
        {
            dr0[i]=dr0[i+1]+1-(v[i]-'0');
            dr1[i]=dr1[i+1]+v[i]-'0';
        }
        int mx=n;
        for(i=1;i<=n;++i)
        {
            mx=min(mx,st0[i]+dr1[i+1]);
            mx=min(mx,st1[i]+dr0[i+1]);
        }
        cout<<mx<<'\n';
    }
    return 0;
}