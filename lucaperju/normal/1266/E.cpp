#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
int v[200005];
map<long long,int>mp;
long long hsh (int a, int b)
{
    return 1LL*(a*10000000LL+b);
}
void scoate (int pz, long long &s)
{
    ++v[pz];
    if(v[pz]>0)
        ++s;
}
void baga (int pz, long long &s)
{
    --v[pz];
    if(v[pz]>=0)
        --s;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,m,k,i,j,s=0,rz=0,a,b,f,mx=0;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        s+=v[i];
    }
    cin>>m;
    for(i=1;i<=m;++i)
    {
        int a,b,c;
        cin>>a>>b>>c;
        long long cat=hsh(a,b);
        if(mp[cat])
            scoate(mp[cat],s);
        baga(c,s);
        mp[cat]=c;
        cout<<s<<'\n';
    }
    return 0;
}