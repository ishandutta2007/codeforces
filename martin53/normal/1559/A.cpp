#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

void solve()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    int outp=inp[1];

    for(int i=1;i<=n;i++)outp=outp&inp[i];

    printf("%i\n",outp);
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