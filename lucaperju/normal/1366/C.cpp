#include <bits/stdc++.h>

using namespace std;
int v[50][50];
int sum[150];
int cnt[150];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    unsigned long long m,k,t,i,j,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0;
    cin>>t;
    long long n;
    while(t--)
    {
        cin>>n>>m;
        for(i=1;i<=n+m;++i)
            sum[i]=cnt[i]=0;
        for(i=1;i<=n;++i)
            for(j=1;j<=m;++j)
                cin>>v[i][j];
        int rz=0;
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=m;++j)
            {
                sum[i+j-1]+=v[i][j];
                ++cnt[i+j-1];
            }
        }
        for(i=1;i<=(n+m-1)/2;++i)
        {
            sum[i]+=sum[n+m-i];
            cnt[i]+=cnt[n+m-i];
            rz+=min(sum[i],cnt[i]-sum[i]);
        }
        cout<<rz<<'\n';
    }
    return 0;
}