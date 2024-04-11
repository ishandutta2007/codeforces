#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;

    scanf("%i",&n);

    n--;

    int pwr=0;

    while((1<<pwr)*2<=n)pwr++;

    for(int j=(1<<pwr)-1;j>=0;j--)
        printf("%i ",j);

    for(int j=(1<<pwr);j<=n;j++)
        printf("%i ",j);

    printf("\n");
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