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
        cin>>n>>m;
        long long pas=1LL<<40;
        k=0;
        while(pas)
        {
            if((k+pas)-(k+pas)/n<=m)
                k+=pas;
            pas>>=1LL;
        }
        if(k%n==0)
            --k;
        cout<<k<<'\n';
    }
    return 0;
}