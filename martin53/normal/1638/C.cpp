#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n;

int solve()
{
    scanf("%i",&n);

    int outp=0,MX=0;

    for(int i=1;i<=n;i++)
    {
        int cur;

        scanf("%i",&cur);

        MX=max(MX,cur);

        if(MX==i)outp++;
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