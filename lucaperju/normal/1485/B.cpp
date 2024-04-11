#include <bits/stdc++.h>
using namespace std;
int sp[100005],v[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,n,i,j,m,k=0;
    cin>>n>>m>>k;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        sp[i]=max(0,(v[i]-v[i-1]-1)*2);
        sp[i]+=sp[i-1];
    }
    for(i=1;i<=m;++i)
    {
        int a,b;
        cin>>a>>b;
        long long rz=0;
        rz+=v[a]-1;
        rz+=k-v[b];
        rz+=sp[b]-sp[a];
        cout<<rz<<'\n';
    }
    return 0;
}