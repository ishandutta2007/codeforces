#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,n,i,m,j,k,mx,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        cout<<max(min(a,b)*2,max(a,b))*max(min(a,b)*2,max(a,b))<<'\n';
    }
    return 0;
}