#include <bits/stdc++.h>

using namespace std;
long long v[200005];
int minst[200005];
map<long long,long long>mp;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long i,j,mx=0,n,s=0,rz=0;
    int k;
    cin>>n;
    mp[0]=1;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        s+=v[i];
        minst[i]=mp[s];
        mp[s]=i+1;
    }
    for(i=1;i<=n;++i)
        minst[i]=max(minst[i],minst[i-1]);
    for(i=1;i<=n;++i)
        rz+=i-minst[i];
    cout<<rz;
    return 0;
}