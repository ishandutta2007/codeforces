#include<bits/stdc++.h>
using namespace std;

const int nmax=5e3+42;

int n,x,inp[nmax];

int MX[nmax];

void solve()
{
    scanf("%i%i",&n,&x);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=1;i<=n;i++)MX[i]=-1e9;

    for(int i=1;i<=n;i++)
    {
        int sum=0;

        for(int j=i;j<=n;j++)
        {
            sum+=inp[j];

            MX[j-i+1]=max(MX[j-i+1],sum);
        }
    }

    for(int i=0;i<=n;i++)
    {
        int outp=0;

        for(int j=0;j<=n;j++)
            outp=max(outp,MX[j]+min(j,i)*x);

        printf("%i ",outp);
    }

    printf("\n");
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        solve();
    }

    return 0;
}