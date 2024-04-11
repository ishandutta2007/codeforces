#include<bits/stdc++.h>
using namespace std;

int solve()
{
    int n,m;

    scanf("%i%i",&n,&m);

    int outp=0,lower=0;

    for(int bits=29;bits>=0;bits--)
    {
        int add=(n&(1<<bits));

        if(lower+add+(1<<bits)-1>m)lower=lower+add;
        else outp=outp+(1<<bits),lower=lower+(1<<bits)-add;

        //cout<<bits<<" "<<outp<<" "<<lower<<endl;
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