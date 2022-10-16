#include <bits/stdc++.h>
using namespace std;
vector <int> v[5005];
int val[5005];
long long dst (long long a, long long b, long long n)
{
    if(a<=b)
        return b-a;
    else
    {
        b+=n;
        return b-a;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long s=0,i=0,j=0,n,m,d,s1=0,ra,rb,rc,rd,ok,mx=0,a,b;
    char c;
    cin>>n>>m;
    for(i=1;i<=m;++i)
    {
        cin>>a>>b;
        v[a].push_back(b);
    }
    for(i=1;i<=n;++i)
    {
        long long mn=999999;
        s=(v[i].size()-1)*n;
        for(j=0;j<v[i].size();++j)
            mn=min(mn,dst(i,v[i][j],n));
        if(v[i].size()==0)
        {
            val[i]=0;
            continue;
        }
        s+=mn;
        val[i]=s;
    }
    for(i=1;i<=n;++i)
    {
        if(val[i]!=0)
            mx=max(mx,val[i]+i-1);
    }
    for(i=1;i<=n;++i)
    {
        cout<<mx<<' ';
        --mx;
        if(val[i] && val[i]+n-1>mx)
            mx=val[i]+n-1;
    }
    return 0;
}