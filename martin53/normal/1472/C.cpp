#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax],score[nmax];

int solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    int outp=0;

    for(int i=n;i>=1;i--)
    {
        score[i]=inp[i];

        if(i+inp[i]<=n)score[i]+=score[i+inp[i]];

        outp=max(outp,score[i]);
    }

    return outp;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        printf("%i\n",solve());
    }

    return 0;
}