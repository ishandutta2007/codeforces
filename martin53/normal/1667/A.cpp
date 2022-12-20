#include<bits/stdc++.h>
using namespace std;

const int nmax=5e3+42;

int n,inp[nmax];

int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    long long outp=1e18;

    for(int i=1;i<=n;i++)
    {
        //b[i]=0

        long long cur=0;

        long long prv=0;

        for(int j=i+1;j<=n;j++)
        {
            long long now=prv/inp[j]+1;

            cur+=now;

            prv=now*inp[j];
        }

        prv=0;

        for(int j=i-1;j>=1;j--)
        {
            long long now=-prv/inp[j]+1;

            cur+=now;

            prv=-now*inp[j];
        }

        //cout<<i<<" -> "<<cur<<endl;

        outp=min(outp,cur);
    }

    printf("%lld\n",outp);

    return 0;
}