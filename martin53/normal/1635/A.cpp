#include<bits/stdc++.h>
using namespace std;

int solve()
{
    int n;

    int ret=0;

    scanf("%i",&n);

    for(int i=1;i<=n;i++)
    {
        int cur;
        scanf("%i",&cur);

        ret=ret|cur;
    }

    return ret;
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