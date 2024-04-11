#include<bits/stdc++.h>
using namespace std;

int solve()
{
    int n,s;

    scanf("%i%i",&n,&s);

    n=n/2+1;

    return s/n;
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