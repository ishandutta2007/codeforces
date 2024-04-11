#include <bits/stdc++.h>

using namespace std;
long long fv[1003][5];
int main()
{
    ios_base::sync_with_stdio(0);
    long long t,i,j=0,cnt=0,k=0,mn=2,n,m,is,js,ib,jb,s=0,a,b,st,dr,mx=0,cur=0;
    cin>>n>>m;
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=m;++j)
        {
            char c;
            cin>>c;
            ++fv[j][c-'A'];
        }
    }
    for(i=1;i<=m;++i)
    {
        cin>>a;
        mx=fv[i][0];
        mx=max(mx,fv[i][1]);
        mx=max(mx,fv[i][2]);
        mx=max(mx,fv[i][3]);
        mx=max(mx,fv[i][4]);
        s+=a*mx;
    }
    cout<<s;
    return 0;
}