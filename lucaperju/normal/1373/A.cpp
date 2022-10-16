#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long i,j,n,t,m,k,n1;
    cin>>t;
    while(t--)
    {
        long long a,b,c;
        cin>>a>>b>>c;
        if(a>=c)
        {
            cout<<-1<<' ';
        }
        else
            cout<<1<<' ';
        if(c>=a*b)
            cout<<-1<<' ';
        else
            cout<<b<<' ';
        cout<<'\n';
    }
    return 0;
}