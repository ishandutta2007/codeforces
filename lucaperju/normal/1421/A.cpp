#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,i,j,s=0,k,n,m,mx=0;
    cin>>t;
    while(t--)
    {
        long long a,b;
        cin>>a>>b;
        int c=(a&b);
        cout<<(a xor c)+(b xor c)<<'\n';
    }
    return 0;
}