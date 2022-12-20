#include<bits/stdc++.h>
using namespace std;

const int nmax=1e3+42;

int n,inp[nmax];

int ask(int small,int large)
{
    if(small>large)swap(small,large);

    int ret=0;

    while(2*small<large)
    {
        ret++;

        small=small*2;
    }

    return ret;
}
int solve()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    int outp=0;

    for(int i=1;i<n;i++)
        outp+=ask(inp[i],inp[i+1]);

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