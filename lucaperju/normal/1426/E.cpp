#include <bits/stdc++.h>
using namespace std;
map<long long,int>mp;
long long v[200005];
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,i,j,k,n,q,m;
    cin>>n;
    long long a,b,c,x,y,z;
    cin>>a>>b>>c>>x>>y>>z;
    long long mx=0,mn=0;
    mx=min(a,y)+min(b,z)+min(c,x);
    mn=n-min(a,x+z)-min(b,y+x)-min(c,z+y);
    cout<<mn<<' '<<mx<<'\n';
    return 0;
}