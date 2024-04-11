#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
using namespace std;
const long long INF=100000000000000LL;
int v[505][505];
int main()
{
   /* ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand ( time(NULL) );*/
    long long pz,add=1,t,h,i,j,n,mn=10000030LL*10000030LL,k=0,mx=-999999999999LL,tot,m,obj,cnt=0,cnti=0,nri=0,b2,a3,b3,a,b,ok=0;
    long long ra,rb,dv=-1,dv1=-1;
    cin>>n>>m;
    int s=0;
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=m;++j)
            cin>>v[i][j];
        for(j=2;j<=m;++j)
            if(v[i][j]!=v[i][j-1])
            {
                ok=1;
                pz=i;
            }
        s=(s xor v[i][1]);
    }
    if(s!=0)
    {
        cout<<"TAK\n";
        for(i=1;i<=n;++i)
            cout<<1<<' ';
    }
    else
    {
        if(ok==0)
        {
            cout<<"NIE";
            return 0;
        }
        cout<<"TAK\n";
        int pzc;
        for(j=1;j<=m;++j)
            if(v[pz][j]!=v[pz][1])
            {
                pzc=pz;
                pz=j;
                break;
            }
        for(i=1;i<=n;++i)
        {
            if(i==pzc)
                cout<<pz<<' ';
            else
                cout<<1<<' ';
        }
    }
    return 0;
}