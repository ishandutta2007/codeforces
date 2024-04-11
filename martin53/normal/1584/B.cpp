#include<bits/stdc++.h>
using namespace std;

int solve()
{
    int n,m;

    scanf("%i%i",&n,&m);

    return (n*m+2)/3;
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