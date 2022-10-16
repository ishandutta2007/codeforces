#include <bits/stdc++.h>

using namespace std;
int v[100005];
int rz[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    unsigned long long m,k,t,i,j,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
        {
            cin>>v[i];
        }
        j=0;
        for(i=1;i<=n;++i)
        {
            if(i==1 || i==n || (v[i]>v[i-1] && v[i]>v[i+1]) || (v[i]<v[i-1] && v[i]<v[i+1]))
            {
                rz[++j]=v[i];
            }
        }
        cout<<j<<'\n';
        for(i=1;i<=j;++i)
            cout<<rz[i]<<' ';
        cout<<'\n';
    }
    return 0;
}