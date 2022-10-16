//#include <fstream>
#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
using namespace std;
const long long INF=100000000000000LL;
bool rz[1003][1003];
const int kkt[36] = {0,1,1,1,0,0,0,0,1,0,1,0,0,0,0,1,1,1,0,1,0,0,1,1,1,0,0,0,0,1,1,1,0,0,0,0};
int main()
{
   /* ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand ( time(NULL) );*/
    long long p,add=1,t,h,i,j,n,mn=10000030LL*10000030LL,k=0,mx=-999999999999LL,tot,m,obj,cnt=0,cnti=0,nri=0,b2,a3,b3,a,b,ok=0;
    long long ra,rb,dv=-1,dv1=-1;
    cin>>n;
    if(n%2==0)
    {
        if(n<6)
        {
            cout<<-1;
            return 0;
        }
        int pz=0;
        for(i=1;i<=6;++i)
            for(j=1;j<=6;++j)
                rz[i][j]=kkt[pz++];
        for(k=8;k<=n;k+=2)
        {
            /// k-1 -> k | toate -> k-1 | k -> toate
            rz[k-1][k]=1;
            for(i=1;i<k-1;++i)
                rz[i][k-1]=rz[k][i]=1;
        }
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=n;++j)
                cout<<rz[i][j]<<' ';
            cout<<'\n';
        }
        return 0;
    }
    for(i=1;i<=n;++i)
        for(j=i%n+1;j!=i;j=(j+1)%n+1)
            rz[i][j]=true;
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=n;++j)
            cout<<rz[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}