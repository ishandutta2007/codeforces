#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;

    scanf("%i",&n);

    int start=1;

    if(n%2)
    {
        printf("2 3 1 ");
        start=4;
    }

    for(int i=start;i<=n;i=i+2)
        printf("%i %i ",i+1,i);

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