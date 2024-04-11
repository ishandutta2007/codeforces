#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,MX,inp[nmax];

int solve()
{
    scanf("%i%i",&MX,&n);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    sort(inp+1,inp+n+1);

    int cat=0,outp=0;

    for(int i=n;i>=1;i--)
        if(cat<inp[i])
        {
            outp++;
            cat+=MX-inp[i];
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