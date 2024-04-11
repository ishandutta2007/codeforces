#include <bits/stdc++.h>

using namespace std;
int v[200005];
int main()
{
    long long n,i,j,m,mn=9999999,pz,a,b,s=0,x,y,k;
    long long mx=0;
    char c;
    cin>>n>>k;
    for(i=1;i<=n;++i)
    {
        cin>>a;
        ++v[a%k];
    }
    s+=v[0]/2;
    for(i=1;i<k;++i)
    {
        if(i!=k-i)
        {
            s+=min(v[i],v[k-i]);
            v[i]=0;
        }
        else
            s+=v[i]/2;
    }
    cout<<s*2;
    return 0;
}