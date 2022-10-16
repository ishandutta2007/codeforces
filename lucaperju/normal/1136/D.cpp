#include <bits/stdc++.h>
using namespace std;
int fv[300005],vi[300005];
vector <int> v[300005];
int main()
{
    long long n,i,j,m,mn=9999999,pz,a,b,s,x,y,k=1,mx=0,cnt=0,val;
    cin>>n>>m;
    for(i=1;i<=n;++i)
        cin>>vi[i];
    for(i=1;i<=m;++i)
    {
        cin>>a>>b;
        v[b].push_back(a);
    }
    for(j=0;j<v[vi[n]].size();++j)
        ++fv[v[vi[n]][j]];
    for(i=n-1;i>=1;--i)
    {
        if(fv[vi[i]]==k)
            ++cnt;
        else
        {
            for(j=0;j<v[vi[i]].size();++j)
                ++fv[v[vi[i]][j]];
            ++k;
        }
    }
    cout<<cnt;
    return 0;
}