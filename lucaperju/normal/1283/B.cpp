#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n,t,i,j,k=0,pas=1<<20,m,mx=0,sc,rz;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int a=n/k;
        cout<<min(n,a*k+k/2)<<'\n';
    }
    return 0;
}