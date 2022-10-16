#include <bits/stdc++.h>
using namespace std;
struct ura
{
    int a,b;
};
int v[300003];
long long c[300003];
int main()
{
    ios_base::sync_with_stdio(false);///mlc
    long long t,n,i,j,k=0,m;
    long long x1,y1,x2,y2,pas;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=1;i<=n;++i)
            cin>>v[i];
        for(i=1;i<=m;++i)
            cin>>c[i];
        sort(v+1,v+n+1);
        int j=1;
        long long s=0;
        for(i=n;i>=1;--i)
        {
            if(j<v[i])
                s+=c[j++];
            else
                s+=c[v[i]];
        }
        cout<<s<<'\n';
    }
    return 0;
}