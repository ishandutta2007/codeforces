#include<bits/stdc++.h>
using namespace std;

int solve()
{
    int n,cur,even=0;

    scanf("%i",&n);

    for(int i=1;i<=n;i++)
    {
        scanf("%i",&cur);

        if(cur%2==0)even++;
    }

    return min(even,n-even);
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