#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k;

    scanf("%i%i",&n,&k);

    if((n-2+1)/2<k)printf("-1\n");
    else
    {
        for(int i=1;i<=k;i++)
            printf("%i %i ",i,n+1-i);

        for(int i=n-k;i>k;i--)printf("%i ",i);
        printf("\n");
    }
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