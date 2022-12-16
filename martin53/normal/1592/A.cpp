#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int inp[nmax];

int eval(int h,int big,int small)
{
    int both=h/(big+small);

    if(h%(big+small)==0)return 2*both;
    else if(h%(big+small)<=big)return 2*both+1;
    else return 2*both+2;
}
int solve()
{
    int n,h;
    scanf("%i%i",&n,&h);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    sort(inp+1,inp+n+1);

    return eval(h,inp[n],inp[n-1]);
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