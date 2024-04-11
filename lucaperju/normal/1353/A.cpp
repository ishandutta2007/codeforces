#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long m,n,i,t,j,k,mx,p,mxx=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        if(n==1)
        {
            cout<<0<<'\n';
        }
        else if(n==2)
        {
            cout<<m<<'\n';
        }
        else
            cout<<2*m<<'\n';
    }
    return 0;
}