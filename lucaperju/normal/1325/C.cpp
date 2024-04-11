#include <bits/stdc++.h>
using namespace std;
int va[100005],vb[100005],rz[100005];
vector <int>v[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long m,ok=0,i,j=0,cnt=0,s=0,h,l,r,t,n,k;
    cin>>n;
    for(i=1;i<n;++i)
    {
        int a,b;
        cin>>va[i]>>vb[i];
        v[va[i]].push_back(i);
        v[vb[i]].push_back(i);
        rz[i]=-1;
    }
    for(i=1;i<=n;++i)
    {
        if(v[i].size()==1)
            ++cnt;
    }
    if(cnt==2)
    {
        for(i=1;i<n;++i)
            cout<<i-1<<'\n';
    }
    else
    {
        int cnt=0;
        for(i=1;i<=n;++i)
        {
            if(v[i].size()==1)
                rz[v[i][0]]=cnt++;
        }
        for(i=1;i<n;++i)
        {
            if(rz[i]==-1)
                rz[i]=cnt++;
        }
        for(i=1;i<n;++i)
            cout<<rz[i]<<'\n';
    }
    return 0;
}