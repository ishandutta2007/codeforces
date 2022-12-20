#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    scanf("%i",&n);

    while(n>=111&&n%11)n=n-111;

    if(n%11==0)printf("YES\n");
    else printf("NO\n");
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