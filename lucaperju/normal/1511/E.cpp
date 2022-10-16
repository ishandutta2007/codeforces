#include <bits/stdc++.h>
using namespace std;
const int mod=998244353; /// bruh aveam 998224353
long long sum[300003];
long long put2[300003];
vector<int>v[300003];
int main()
{
    ios_base::sync_with_stdio(false);
    long long t,n,m,i,j;
    cin>>n>>m;
    put2[0]=1;
    for(i=1;i<=300000;++i)
        put2[i]=2LL*put2[i-1]%mod;
    sum[2]=1;
    sum[3]=2;
    sum[4]=5;
    sum[5]=10;
    for(i=6;i<=300000;++i)
    {
        if(i%2==1)
        {
            sum[i]=sum[i-1]*2LL%mod;
        }
        else
        {
            sum[i]=(sum[i-1]*2LL+1LL)%mod;
        }
    }
    long long rz=0;
    int cntt=0;
    for(i=0;i<n;++i)
    {
        for(j=0;j<m;++j)
        {
            char c;
            cin>>c;
            if(c=='o')
                v[i].push_back(1);
            else
                v[i].push_back(0);
            cntt+=v[i][j];
        }
    }
    int cntc=0;
    for(i=0;i<n;++i)
    {
        cntc=0;
        for(j=0;j<m;++j)
        {
            if(v[i][j]==1)
                ++cntc;
            else
                cntc=0;
            if(cntc>=2)
            {
                if(j==m-1 || v[i][j+1]==0)
                {
                    rz=(rz+put2[cntt-cntc]*1LL*sum[cntc]%mod)%mod;
                }
                else
                {
                    rz=(rz+put2[cntt-cntc-1]*1LL*sum[cntc]%mod)%mod;
                }
            }
        }
    }
    for(j=0;j<m;++j)
    {
        cntc=0;
        for(i=0;i<n;++i)
        {
            if(v[i][j]==1)
                ++cntc;
            else
                cntc=0;
            if(cntc>=2)
            {
                if(i==n-1 || v[i+1][j]==0)
                {
                    rz=(rz+put2[cntt-cntc]*1LL*sum[cntc]%mod)%mod;
                }
                else
                {
                    rz=(rz+put2[cntt-cntc-1]*1LL*sum[cntc]%mod)%mod;
                }
            }
        }
    }
    cout<<rz;
	return 0;
}