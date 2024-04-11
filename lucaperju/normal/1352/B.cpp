#include <bits/stdc++.h>
 
using namespace std;
int rz[2005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long m,n,i,t,j,k,mx,p,mxx=0,a;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        if((n-k+1)%2 && n>=k)
        {
            cout<<"YES\n";
            for(i=1;i<k;++i)
                cout<<1<<' ';
            cout<<n-k+1<<'\n';
        }
        else if(k*2<=n && n%2==0)
        {
            cout<<"YES\n";
            for(i=1;i<k;++i)
                cout<<2<<' ';
            cout<<n-(k-1)*2<<'\n';
        }
        else
            cout<<"NO\n";
    }
    return 0;
}