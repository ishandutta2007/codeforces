#include<bits/stdc++.h>
using namespace std;

long long solve()
{
    long long cnt[2]={0,0};

    int n;
    scanf("%i",&n);

    for(int i=1;i<=n;i++)
    {
        int cur;
        scanf("%i",&cur);

        if(cur<2)cnt[cur]++;
    }

    return (1LL*cnt[1])<<cnt[0];
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        printf("%lld\n",solve());
    }

    return 0;
}