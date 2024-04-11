#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long m,n,i,t,j,k,mx,p,mxx=0,s;
    cin>>n>>s;
    if(n>s/2)
        cout<<"NO\n";
    else
    {
        cout<<"YES\n";
        for(i=1;i<n;++i)
            cout<<1<<' ';
        cout<<s-n+1<<'\n';
        cout<<s/2;
    }
    return 0;
}