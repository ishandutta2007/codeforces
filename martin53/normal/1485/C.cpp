#include<bits/stdc++.h>
using namespace std;

long long solve()
{
    int x,y;

    scanf("%i%i",&x,&y);

    long long outp=0;

    for(int q=1;true;q++)
    {
        int b_low=q+1;
        int b_high=min(y,x/q-1);

        if(b_low>b_high)break;

        outp+=b_high-b_low+1;
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
        printf("%lld\n",solve());
    }

    return 0;
}