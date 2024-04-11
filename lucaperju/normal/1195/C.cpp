#include <bits/stdc++.h>

using namespace std;
long long d[100005][3];
long long a[100005],b[100005];
int main()
{
    ios_base::sync_with_stdio(0);
    long long t,i,j,cnt=0,k=0,mn=2,n,m,is,js,ib,jb;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>a[i];
    for(i=1;i<=n;++i)
        cin>>b[i];
    for(i=1;i<=n;++i)
    {
        d[i][0]=max(d[i-1][0],max(d[i-1][1],d[i-1][2]));
        d[i][1]=max(d[i-1][0],d[i-1][2])+a[i];
        d[i][2]=max(d[i-1][0],d[i-1][1])+b[i];
    }
    cout<<max(d[n][0],max(d[n][1],d[n][2]));
    return 0;
}