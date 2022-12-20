#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

void solve()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    long long sum=0;

    for(int i=1;i<=n;i++)
    {
        sum+=inp[i];

        if(sum<1LL*i*(i-1)/2)
        {
            printf("NO\n");
            return;
        }
    }

    printf("YES\n");
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