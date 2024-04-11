#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int t;
int n,inp[nmax];

int cnt[30];

int solve()
{
    memset(cnt,0,sizeof(cnt));

    scanf("%i",&n);
    for(int i=1;i<=n;i++)
    {
        int cur;
        scanf("%i",&cur);

        for(int j=0;j<30;j++)
            if((cur&(1<<j)))cnt[j]++;
    }

    int g=0;
    for(int j=0;j<30;j++)
        g=__gcd(g,cnt[j]);

    for(int i=1;i<=n;i++)
        if(g%i==0)printf("%i ",i);
    printf("\n");
}

int main()
{
    scanf("%i",&t);

    while(t)
    {
        t--;

        solve();
    }

    return 0;
}