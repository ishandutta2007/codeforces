#include <bits/stdc++.h>

using namespace std;
long long cmmdc (long long a, long long b)
{
    long long r;
    while(b)
    {r=a%b;a=b;b=r;}
    return a;
}
const long long mod=1000000007;
long long d[100005];
long long cur[105][105],put[105][105],rez[105][105];
int main()
{
    long long i,j=0,n,pz=-1,s=0,x,y,z,a,b,c,m,pr,cnt=0,mx=0,mxx=0,x1,y1,x2,y2,cx=0,cy=0;
    cin>>n>>m;
    d[0]=1;
    if(n<=10000)
    {
        for(i=1;i<=n;++i)
        {
            if(i>=m)
                d[i]=d[i-1]+d[i-m];
            else
                d[i]=d[i-1];
            d[i]%=mod;
        }
        cout<<d[n];
        return 0;
    }
    n-=m;
    for(i=1;i<m;++i)
        put[i][i+1]=rez[i][i+1]=1;
    put[m][1]=rez[m][1]=1;
    put[m][m]=rez[m][m]=1;
    while(n>0)
    {
        if(n&1LL)
        {
            for(i=1;i<=m;++i)
            {
                for(j=1;j<=m;++j)
                {
                    long long sc=0;
                    for(int ii=1;ii<=m;++ii)
                        sc=(sc+(rez[i][ii]*1LL*put[ii][j])%mod)%mod;
                    cur[i][j]=sc;
                }
            }
            for(i=1;i<=m;++i)
                for(j=1;j<=m;++j)
                    rez[i][j]=cur[i][j];
            --n;
        }
        else
        {
            for(i=1;i<=m;++i)
            {
                for(j=1;j<=m;++j)
                {
                    long long sc=0;
                    for(int ii=1;ii<=m;++ii)
                        sc=(sc+(put[i][ii]*1LL*put[ii][j])%mod)%mod;
                    cur[i][j]=sc;
                }
            }
            for(i=1;i<=m;++i)
                for(j=1;j<=m;++j)
                    put[i][j]=cur[i][j];
            n>>=1LL;
        }
    }
    long long sc=0;
    for(i=1;i<=m;++i)
    {
        sc=sc+rez[i][m];
        sc%=mod;
    }
    cout<<sc;
}