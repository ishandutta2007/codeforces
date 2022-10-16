#include <bits/stdc++.h>
using namespace std;
long long v[5];
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,n,i,j,mod;
    cin>>t;
    while(t--)
    {
        cin>>v[1]>>v[2]>>v[3]>>v[4];
        sort(v+1,v+5);
        cout<<v[1]*1LL*v[3]<<'\n';
    }
    return 0;
}