#include <bits/stdc++.h>

using namespace std;
char v[505][505];
char rz[505][505];
int main()
{
    ios_base::sync_with_stdio(false);
    int t,n,d,i,j,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=0;i<=n+1;++i)
            for(j=0;j<=m+1;++j)
                v[i][j]=rz[i][j]='.';
        for(i=1;i<=n;++i)
            for(j=1;j<=m;++j)
            {
                cin>>v[i][j];
                rz[i][j]=v[i][j];
            }
        for(i=1;i+3<=n;i+=3)
        {
            for(j=1;j<=m;++j)
                rz[i][j]='X';
            for(j=1;j<=m;++j)
            {
                if(v[i+1][j]=='X' || v[i+2][j]=='X')
                {
                    rz[i+1][j]='X';
                    rz[i+2][j]='X';
                    break;
                }
            }
            if(j==m+1)
                rz[i+1][1]=rz[i+2][1]='X';
        }
        for(j=1;j<=m;++j)
            rz[i][j]='X';
        ++i;
        for(;i<=n;++i)
            for(j=1;j<=m;++j)
            {
                if(v[i][j]=='X')
                {
                    int k=i;
                    rz[k][j]='.';
                    while(rz[k][j]!='X')
                    {
                        rz[k][j]='X';
                        --k;
                    }
                }
            }
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=m;++j)
                cout<<rz[i][j];
            cout<<'\n';
        }
    }
	return 0;
}