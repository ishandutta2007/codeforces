#include<bits/stdc++.h>
using namespace std;

const int nmax=1e3+42,mod=1e9+7;

long long c[nmax][nmax];

void prec()
{
    for(int i=0;i<nmax;i++)
        for(int j=0;j<=i;j++)
            if(j==0||j==i)c[i][j]=1;
            else c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
}

int n;

vector< pair<long long,int> >  mem[64][2*nmax];

long long z;

long long r_original;

long long solve(long long l,long long r,int pos)
{
    if(l>r)return 0;

    long long z_now=(z>>pos);

    if(r==0)return z_now==0;

    int where_r=(r_original>>pos)-r;

    for(auto w:mem[pos][where_r])
        if(w.first==l)return w.second;

    long long ret=0;

    for(int i=z_now%2;i<=n&&i<=r;i+=2)
        ret=(ret+solve((l-i+1)/2,(r-i)/2,pos+1)*c[n][i])%mod;

    //cout<<l<<" "<<r<<" "<<z_now<<" -> "<<ret<<endl;

    mem[pos][where_r].push_back({l,ret});

    return ret;
}

int main()
{
    prec();

    long long l,r;

    scanf("%i%lld%lld%lld",&n,&l,&r,&z);

    r_original=r;

    printf("%i\n",solve(l,r,0));

    return 0;
}