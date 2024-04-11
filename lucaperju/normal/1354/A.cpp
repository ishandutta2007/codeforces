#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    unsigned long long i,t,j,k,mx,p,mxx=0,s,q;
    cin>>t;
    while(t--)
    {
        long long a,b,c,d;
        cin>>a>>b>>c>>d;
        if(b>=a)
        {
            cout<<b<<'\n';
        }
        else if(c<=d)
        {
            cout<<-1<<'\n';
        }
        else
        {
            a-=b;
            long long rz=b;
            b=(c-d);
            cout<<rz+((a-1)/b+1)*c<<'\n';
        }
    }
    return 0;
}