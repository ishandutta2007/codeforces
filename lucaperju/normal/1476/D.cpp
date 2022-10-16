#include <bits/stdc++.h>

using namespace std;
char v[300003];
int st[300003],dr[300003];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long t,n,m,i,j,k,s;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        for(i=1;i<=n;++i)
        {
            if(i==1 || v[i]==v[i-1])
                st[i]=1;
            else
                st[i]=1+st[i-1];
        }
        for(i=n;i>=1;--i)
        {
            if(i==n || v[i]==v[i+1])
                dr[i]=1;
            else
                dr[i]=1+dr[i+1];
        }
        v[n+1]=0;
        for(i=0;i<=n;++i)
        {
            s=1;
            if(v[i]=='L')
                s+=st[i];
            if(v[i+1]=='R')
                s+=dr[i+1];
            cout<<s<<' ';
        }
        cout<<'\n';
    }
    return 0;
}