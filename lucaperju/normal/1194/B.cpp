#include <bits/stdc++.h>

using namespace std;
char v[400005];
int n,m;
int pz (int i, int j)
{
    if(i==0 || j==0)
        return 0;
    return (i-1)*m+j;
}
int sp[400005];
int main()
{
    int t,i,j,c,cnt=0,k,mn=2;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=1;i<=n;++i)
            for(j=1;j<=m;++j)
                cin>>v[(i-1)*m+j];
        for(i=1;i<=n;++i)
            for(j=1;j<=m;++j)
                sp[pz(i,j)]=sp[pz(i-1,j)]+sp[pz(i,j-1)]-sp[pz(i-1,j-1)]+(v[pz(i,j)]=='*');
        int mn=999999999;
        for(i=1;i<=n;++i)
            for(j=1;j<=m;++j)
            {
                int cur=sp[pz(n,j)]-sp[pz(n,j-1)]+sp[pz(i,m)]-sp[pz(i-1,m)]-(v[pz(i,j)]=='*');
                cur=n+m-1-cur;
                mn=min(mn,cur);
            }
        cout<<mn<<'\n';
    }
    return 0;
}