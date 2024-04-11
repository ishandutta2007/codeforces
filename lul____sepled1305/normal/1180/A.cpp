#include<bits/stdc++.h>
using namespace std;
long long i,n;
long long f[101];
int main()
{
    cin>>n;
    f[1]=1;
    for(i=2;i<=n;i++)
    {
        f[i]=f[i-1]+4*(i-1);
    }
    cout<<f[n];
    return 0;
}