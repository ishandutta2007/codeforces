#include <bits/stdc++.h>
using namespace std;
long long mx[200005],s[200005],nrf[200005];
vector<int>v[200005];
long long a[200005];
void dfs (int pz)
{
   // s[pz]=a[pz];
    if(v[pz].size()==0)
        nrf[pz]=1;
    long long mxc=0;
    for(int i=0;i<v[pz].size();++i)
    {
        dfs(v[pz][i]);
        mxc=max(mxc,mx[v[pz][i]]);
        s[pz]+=s[v[pz][i]];
        nrf[pz]+=nrf[v[pz][i]];
    }
    long long ram=mxc*1LL*nrf[pz]-s[pz];
    long long ac=a[pz];
    ac-=ram;
    if(ac>0)
        mx[pz]=mxc+(ac-1LL)/nrf[pz]+1LL;
    else
        mx[pz]=mxc;
    s[pz]+=a[pz];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int s=0,n,i,t,j;
    cin>>n;
    for(i=2;i<=n;++i)
    {
        int b;
        cin>>b;
        v[b].push_back(i);
    }
    for(i=1;i<=n;++i)
        cin>>a[i];
    dfs(1);
    cout<<mx[1]<<'\n';
    return 0;
}