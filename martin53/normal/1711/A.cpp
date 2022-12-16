#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;

    scanf("%i",&n);

    for(int j=2;j<=n;j++)printf("%i ",j);
    printf("1\n");
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