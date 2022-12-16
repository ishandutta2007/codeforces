#include<bits/stdc++.h>
using namespace std;
const int nmax=2e5+42,LIM=1e6+42;
const double TL=2.25;
int n;

long long inp[nmax];

long long output=1e18;

int t=clock();
void print()
{
    printf("%lld\n",output);
    exit(0);
}
long long cnt(long long num)
{
    if(num==1)return 1e18;
    if(1.0*(clock()-t)/CLOCKS_PER_SEC>TL)print();
    long long ret=0;
    for(int i=1;i<=n;i++)
    {
        if(inp[i]>=num)ret=ret+min(inp[i]%num,num-inp[i]%num);
        else ret=ret+num-inp[i]%num;
        if(ret>=output)return ret;
    }
    return ret;
}

bool prime[LIM];//0-> prime
void prec()
{
    int p=2;
    while(p*p<LIM)
    {
        for(int j=p*p;j<LIM;j=j+p)prime[j]=1;
        p++;
        while(prime[p])p++;
    }
}

long long help[nmax];
int pointer=0;

void compress_help()
{
    sort(help+1,help+n+1);
    for(int i=1;i<=n;i++)
        if(help[i]!=help[pointer]&&help[i]!=1)
        {
            pointer++;
            help[pointer]=help[i];
        }
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
    prec();

    scanf("%i",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&inp[i]);
        help[i]=inp[i];
    }

    for(int i=2;i<LIM;i++)
        if(prime[i]==0)
        {
            output=min(output,cnt(i));
            if(i<=10000)
            {
                for(int j=1;j<=n;j++)
                    while(help[j]%i==0)help[j]=help[j]/i;
            }
        }
    compress_help();

    while(1&&pointer)
    {
        int nums=rng()%5+1;

        long long g=0;
        for(int i=1;i<=nums;i++)
        {
            g=__gcd(g,help[rng()%pointer+1]);
        }

        output=min(output,cnt(g));
    }
    printf("%lld\n",output);
    return 0;
}