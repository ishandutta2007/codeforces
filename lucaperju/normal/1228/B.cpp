#include <bits/stdc++.h>

using namespace std;
const int mod=1000000007;
int mat[1003][1003];
int main()
{
    int l,r,i,n,m,j;
    cin>>n>>m;
    for(i=1;i<=n;++i)
    {
        int a;
        cin>>a;
        for(j=1;j<=a;++j)
            mat[i][j]=1;
        mat[i][j]=-1;
    }
    for(i=1;i<=m;++i)
    {
        int a;
        cin>>a;
        for(j=1;j<=a;++j)
        {
            if(mat[j][i]==-1)
            {
                cout<<0;
                return 0;
            }
            mat[j][i]=1;
        }
        if(mat[j][i]==1)
        {
            cout<<0;
            return 0;
        }
        mat[j][i]=-1;
    }
    long long rz=1;
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
        {
            if(mat[i][j]==0)
                rz=(rz*2LL)%mod;
        }
    cout<<rz;
    return 0;
}