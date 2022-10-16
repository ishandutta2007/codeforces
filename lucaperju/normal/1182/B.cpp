#include <bits/stdc++.h>
using namespace std;
char v[505][505];
int main ()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n,m,ta,tb,k=0,i,j,nrc=0,nrd=0,s=0,t,ok=0;
    cin>>n>>m;
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            cin>>v[i][j];
    for(i=2;i<n;++i)
        for(j=2;j<m;++j)
        {
            if(v[i][j]=='*' && v[i-1][j]=='*' && v[i+1][j]=='*' && v[i][j-1]=='*'&& v[i][j+1]=='*')
            {
                ok=1;
                int ci=i;
                while(v[ci][j]=='*')
                    v[ci--][j]='.';
                ci=i+1;
                while(v[ci][j]=='*')
                    v[ci++][j]='.';
                ci=j-1;
                while(v[i][ci]=='*')
                    v[i][ci--]='.';
                ci=j+1;
                while(v[i][ci]=='*')
                    v[i][ci++]='.';
                i=n+1;
                j=m+1;
                break;
            }
        }
    if(ok==0)
    {
        cout<<"NO";
        return 0;
    }
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            if(v[i][j]=='*')
                ok=0;
    if(ok==0)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}