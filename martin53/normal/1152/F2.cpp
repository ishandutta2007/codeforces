#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42,kmax=13,mmax=4,mod=1e9+7,MX=210;

int dp[nmax][kmax][1<<mmax];

int n,k,m;

int bits[1<<mmax];

int hsh(int planets,int mask)
{
    //cout<<planets<<" "<<mask<<endl;
    //assert(planets*(1<<m)+mask<MX);

    return planets*(1<<m)+mask;
}

int SZ;

struct matrix
{
    long long paths[MX][MX];
};
matrix operator *(matrix a,matrix b)
{
    matrix ret;

    for(int i=0;i<MX;i++)
        for(int j=0;j<MX;j++)
            ret.paths[i][j]=0;

    for(int p=0;p<MX;p++)
        for(int i=0;i<MX;i++)
            for(int j=0;j<MX;j++)
            {
                ret.paths[i][j]=(ret.paths[i][j]+a.paths[i][p]*b.paths[p][j])%mod;
            }
    return ret;
}
matrix mem,wanted;

int main()
{
    scanf("%i%i%i",&n,&k,&m);

    SZ=(1<<m)*(k+1);

    for(int i=1;i<(1<<m);i++)
        bits[i]=bits[i/2]+i%2;

    for(int planets=0;planets<=k;planets++)
        for(int mask=0;mask<(1<<m);mask++)
        {
            int new_mask=(mask<<1)%(1<<m);

            //do not take
            mem.paths[hsh(planets,mask)][hsh(planets,new_mask)]++;

            //take
            if(planets<k)
            {
                new_mask++;

                mem.paths[hsh(planets,mask)][hsh(planets+1,new_mask)]+=(bits[mask]+1);
            }
        }

    wanted.paths[0][0]=1;

    while(n)
    {
        if(n%2)wanted=wanted*mem;

        mem=mem*mem;

        n=n/2;
    }
    int outp=0;

    for(int mask=0;mask<(1<<m);mask++)
    {
        outp=(outp+wanted.paths[hsh(0,0)][hsh(k,mask)])%mod;
    }

    printf("%i\n",outp);

    return 0;
}