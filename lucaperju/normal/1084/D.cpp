#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
long long vv[300005],viz[300005],mxtot=-99999999;
vector<int>v[300005];
vector<long long>val[300005];
long long dfs (int poz)
{
    long long mx1=0,mx2=0;
    viz[poz]=1;
    for(int i=0;i<v[poz].size();++i)
    {
        long long nn=v[poz][i],cur=0;
        if(!viz[nn])
        {
            cur=dfs(nn);
            cur-=val[poz][i];
            if(cur<0)
                cur=0;
            if(cur>mx1)
            {
                mx2=mx1;
                mx1=cur;
            }
            else
            if(cur>mx2)
                mx2=cur;
        }
    }
    if(max(mx1+mx2+vv[poz],mx1+vv[poz])>mxtot)
        mxtot=max(mx1+mx2+vv[poz],mx1+vv[poz]);
    return mx1+vv[poz];
}
int main()
{
    long long i,n,mx=0;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>vv[i];
    for(i=1;i<n;++i)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back(b);
        v[b].push_back(a);
        val[a].push_back(c);
        val[b].push_back(c);
    }
    i=dfs(1);
    cout<<mxtot;
}