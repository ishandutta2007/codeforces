#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
//int v[200005];
long long v[200],fv[10004];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie();cout.tie();
    long long n,k,i,j=0,cnt=0,pzs=1,psj=1,cur=1,pz,t,mn=9999999999,mx=0;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        ++fv[v[i]];
        mx=max(mx,v[i]);
    }
    cout<<mx<<' ';
    for(i=1;i<=mx;++i)
        if(mx%i==0)
            --fv[i];
    for(i=1;i<=10000;++i)
        if(fv[i])
            mx=i;
    cout<<mx;
    return 0;
}