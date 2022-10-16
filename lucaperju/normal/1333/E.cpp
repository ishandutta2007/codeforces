#include <bits/stdc++.h>

using namespace std;
int rz[505][505];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long i,j,mx=0,n;
    int k;
    cin>>n;
    if(n<=2)
    {
        cout<<-1;
        return 0;
    }
    if(n==3)
    {
        cout<<"1 6 8\n9 5 7\n3 4 2";
        return 0;
    }
    if(n==4)
    {
        cout<<"4 3 6 12 \n7 5 9 15 \n14 1 11 10 \n13 8 16 2";
        return 0;
    }
    rz[4][n-1]=n*n;
    rz[2][n]=n*n-1;
    rz[1][n]=n*n-2;
    rz[2][n-1]=n*n-3;
    rz[1][n-2]=n*n-4;
    k=0;
    for(i=1;i<=n-3;++i)
        rz[1][i]=++k;
    rz[1][n-1]=++k;
    rz[3][n-1]=++k;
    for(i=5;i<=n;++i)
        rz[i][n-1]=++k;
    for(i=n;i>=3;--i)
        rz[i][n]=++k;
    for(i=n-2;i>=2;--i)
        rz[3][i]=++k;
    for(i=2;i<=n-2;++i)
        rz[2][i]=++k;
    rz[2][1]=++k;
    rz[3][1]=++k;
    for(j=1;j<=n-2;++j)
    {
        if(j&1)
            for(i=4;i<=n;++i)
                rz[i][j]=++k;
        else
            for(i=n;i>=4;--i)
                rz[i][j]=++k;
    }
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=n;++j)
            cout<<rz[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}