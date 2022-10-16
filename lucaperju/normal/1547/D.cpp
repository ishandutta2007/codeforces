#include <bits/stdc++.h>
using namespace std;
int a[103],b[103];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long q,m,i,j,l,r,t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int prec=0;
        for(i=1;i<=n;++i)
        {
            int a;
            cin>>a;
            int vlc=prec-(prec&a);
            cout<<vlc<<' ';
            prec=(vlc^a);
        }
        cout<<'\n';
    }
    return 0;
}