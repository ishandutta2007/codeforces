#include <bits/stdc++.h>
using namespace std;
int rz[505][505],n;
int v[505];
void solve (int val)
{
    int i;
    for(i=val;i<=n;++i)
    {
        if(rz[i][i-val+1]==0)
        {
            break;
        }
    }
    rz[i][i-val+1]=val;
    int j=i-val+1;
    int pzv,pzc;
    for(int k=val-1;k>=1;--k)
    {
        for(int jj=1;jj<=n;++jj)
        {
            if(v[jj]==val)
                pzv=jj;
            if(v[jj]==k)
                pzc=jj;
        }
        if(pzc<pzv)
            ++j;
        else
            --i;
        rz[i][j]=val;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long i,m,j,k,cnt,t;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i];
    for(i=n;i>=1;--i)
        solve(i);
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=i;++j)
        {
            cout<<rz[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}