#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;

int solve()
{
    int n;
    scanf("%i",&n);
    n=n*2;

    long long outp=1;
    for(int i=3;i<=n;i++)outp=outp*i%mod;
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