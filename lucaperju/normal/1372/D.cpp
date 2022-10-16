#include <bits/stdc++.h>
using namespace std;
int v[200005];
long long st[200005],dr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long m,i,j,t,k;
        int n;
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        if(n==1)
        {
            cout<<v[1]<<'\n';
            return 0;
        }
        st[1]=v[1];
        st[2]=v[2];
        for(i=3;i<=n;++i)
            st[i]=v[i]+st[i-2];
        dr[n]=v[n];
        dr[n-1]=v[n-1];
        for(i=n-2;i>=1;--i)
        {
            dr[i]=v[i]+dr[i+2];
        }
        long long mx=0;
        for(i=1;i<n;++i)
        {
            mx=max(mx,st[i]+dr[i+1]);
        }
        cout<<mx<<'\n';
    return 0;
}