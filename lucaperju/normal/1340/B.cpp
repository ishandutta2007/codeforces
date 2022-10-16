#include <bits/stdc++.h>
using namespace std;
int n;
char mat[10][8]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
short dp[2003][2003];
char v[2003][10];
int cat (int pz, int cif)
{
    int cnt=0;
    for(int i=0;i<=6;++i)
    {
        if(v[pz][i]=='1' && mat[cif][i]=='0')
            return -1;
        if(v[pz][i]=='0' && mat[cif][i]=='1')
            ++cnt;
    }
    return cnt;
}
bool dfs (int pz, int k)
{
    if(dp[pz][k])
    {
        if(dp[pz][k]==-1)
            return false;
        return true;
    }
    int i;
    for(i=0;i<=9;++i)
    {
        int vlc=cat(pz,i);
        if(vlc==-1)
            continue;
        if(k-vlc<0)
            continue;
        if(!dfs(pz+1,k-vlc))
            continue;
        dp[pz][k]=1;
    }
    if(dp[pz][k]==0)
        dp[pz][k]=-1;
    if(dp[pz][k]==-1)
        return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t,i,k,j;
    cin>>n>>k;
    for(i=1;i<=n;++i)
        cin>>v[i];
    for(i=1;i<=k;++i)
        dp[n+1][i]=-1;
    dp[n+1][0]=1;
    dfs(1,k);
    if(dp[1][k]==-1)
    {
        cout<<-1;
        return 0;
    }
    for(i=1;i<=n;++i)
    {
        for(j=9;j>=0;--j)
        {
            int vlc=cat(i,j);
            if(vlc==-1)
                continue;
            if(k-vlc<0)
                continue;
            if(dp[i+1][k-vlc]==-1)
                continue;
            cout<<j;
            k-=vlc;
            break;
        }
    }
    return 0;
}