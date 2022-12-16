#include<bits/stdc++.h>
using namespace std;

int solve()
{
    int n,x,ret=0;

    scanf("%i",&n);

    for(int i=1;i<=n;i++)
    {
        scanf("%i",&x);
        if(x!=2)ret++;
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