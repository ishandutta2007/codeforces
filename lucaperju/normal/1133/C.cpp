#include <bits/stdc++.h>

using namespace std;
int v[200005];
int main()
{
    long long n,i,j,m,mn=9999999,pz,a,b,s,x,y;
    long long mx=0;
    char c;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    sort(v+1,v+n+1);
    i=j=1;
    while(j<=n)
    {
        if(v[j]-v[i]<=5)
        {
            mx=max(mx,j-i+1);
            ++j;
        }
        else
            ++i;
    }
    cout<<mx;
    return 0;
}