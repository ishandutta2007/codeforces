#include <bits/stdc++.h>
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n,m,ta,tb,k=0,i,j,nrc=0,nrd=0,s=0,t;
    cin>>n;
    if(n%2==1)
        cout<<0;
    else
    {
        int rz=1;
        n/=2;
        for(i=1;i<=n;++i)
            rz<<=1;
        cout<<rz;
    }
    return 0;
}