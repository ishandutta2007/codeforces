#include <bits/stdc++.h>
using namespace std;
map<long long,int>mp;
long long v[200005];
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long t,i,j,k,n,q,m;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        v[i]+=v[i-1];
    }
    int prec=0,cnt=0;
    for(i=0;i<=n;++i)
    {
        if(mp[v[i]])
        {
            ++cnt;
            for(j=prec;j<i-1;++j)
                mp[v[j]]=0;
            prec=i-1;
        }
        mp[v[i]]=1;
    }
    cout<<cnt<<'\n';
    return 0;
}