#include <bits/stdc++.h>

using namespace std;
long long cmmdc (long long a, long long b)
{
    long long r;
    while(b)
    {r=a%b;a=b;b=r;}
    return a;
}
int v[300005],xp[300005],fv1[1048586],fv2[1048586];
int main()
{
    long long i,j=0,n,k=0,pz=-1,s=0,x,y,z,a,b,c,m,pr;
    cin>>n;
    ++fv2[0];
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        xp[i]=xp[i-1]^v[i];
        if(i&1)
        {
            s+=fv1[xp[i]];
            ++fv1[xp[i]];
        }
        else
        {
            s+=fv2[xp[i]];
            ++fv2[xp[i]];
        }
    }
    cout<<s;
}