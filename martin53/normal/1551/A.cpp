#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    scanf("%i",&n);

    int md=n/3;

    if(n%3==0)printf("%i %i\n",md,md);
    else if(n%3==1)printf("%i %i\n",md+1,md);
    else printf("%i %i\n",md,md+1);
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