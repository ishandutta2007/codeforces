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
        long long x,y;
        cin>>x>>y>>n;
        long long pas=1<<30;
        k=0;
        while(pas)
        {
            if((k+pas)*x+y<=n)
                k+=pas;
            pas>>=1LL;
        }
        cout<<k*x+y<<'\n';
    }
    return 0;
}