#include <bits/stdc++.h>

using namespace std;

char v[100005];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long t,i,n,k,d,m,j=0,tt,p,K,cat=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=1;i<=n;++i)
            cin>>v[i];
        int c1=0,c2=0;
        for(i=1;i<=n && v[i]=='0';++i,++c1);
        if(i==n+1)
        {
            cout<<"0\n";
            continue;
        }
        for(i=n;i>=1 && v[i]=='0';--i,++c2);
        long long s=0;
        for(i=1;i<n;++i)
        {
            s+=(v[i]=='1')*10 + (v[i+1]=='1');
        }
        int ok1=0;
        if(v[n]!='1' && c2<=k)
        {
            s-=10;
            if(v[1]=='1' && c2==n-1)
                ++s;
            k-=c2;
            ok1=1;
        }
        if(v[1]!='1' && c1<=k && (c1+c2!=n-1 || ok1==0) && c1!=n-1)
        {
            --s;
        }
        cout<<s<<'\n';
    }
    return 0;
}