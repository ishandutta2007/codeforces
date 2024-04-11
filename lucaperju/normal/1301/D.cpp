#include <bits/stdc++.h>
using namespace std;
char v[1000006];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,m,i,j,t,k,cur=0,cnt=0;
    cin>>n>>m>>k;
    if(k>4*n*m-2*n-2*m)
    {
        cout<<"NO";
        return 0;
    }
    for(i=1;i<n;++i)
    {
        for(j=1;j<m;++j)
            v[++cur]='R';
        for(j=1;j<m;++j)
            v[++cur]='L';
        v[++cur]='D';
    }
    for(j=1;j<m;++j)
    {
        v[++cur]='R';
        for(i=1;i<n;++i)
            v[++cur]='U';
        for(i=1;i<n;++i)
            v[++cur]='D';
    }
    for(j=1;j<m;++j)
        v[++cur]='L';
    for(i=1;i<n;++i)
        v[++cur]='U';
    for(i=1;i<=k;++i)
        if(v[i]!=v[i-1])
            ++cnt;
    cout<<"YES\n";
    cout<<cnt<<'\n';
    cnt=0;
    for(i=1;i<=k;++i)
    {
        ++cnt;
        if(i==k || v[i]!=v[i+1])
        {
            cout<<cnt<<' '<<v[i]<<'\n';
            cnt=0;
        }
    }
    return 0;
}