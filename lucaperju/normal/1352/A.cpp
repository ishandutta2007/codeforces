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
        cin>>n;
        int cnt=0;
        p=1;
        while(n>9)
        {
            if(n%10)
                rz[++cnt]=p*(n%10);
            p*=10;
            n/=10;
        }
        rz[++cnt]=n*p;
        cout<<cnt<<'\n';
        for(i=1;i<=cnt;++i)
            cout<<rz[i]<<' ';
        cout<<'\n';
    }
    return 0;
}