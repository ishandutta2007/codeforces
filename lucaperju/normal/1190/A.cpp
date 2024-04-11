#include <bits/stdc++.h>

using namespace std;
long long v[100005];
int main()
{
    long long n,m,i,j,a,b,c,cnt=0,k;
    cin>>n>>m>>k;
    for(i=1;i<=m;++i)
        cin>>v[i];
    i=1;
    long long dr=(v[i]-1)/k*k+k;
    while(i<=m)
    {
        for(j=i+1;j<=m && v[j]<=dr;++j);
        dr+=j-i;
        ++cnt;
        i=j;
        long long cvi=v[i]-dr;
        if(dr<v[i])
        dr+=(cvi-1)/k*1LL*k+k;
    }
    cout<<cnt;
    return 0;
}