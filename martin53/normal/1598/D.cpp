#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n;
pair<int,int> inp[nmax];

int cnt_a[nmax],cnt_b[nmax];

long long solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%i%i",&inp[i].first,&inp[i].second);

        cnt_a[i]=0;
        cnt_b[i]=0;
    }

    for(int i=1;i<=n;i++)
    {
        cnt_a[inp[i].first]++;
        cnt_b[inp[i].second]++;
    }

    long long ret=1LL*n*(n-1)*(n-2)/6;

    for(int i=1;i<=n;i++)
        ret-=1LL*(cnt_a[inp[i].first]-1)*(cnt_b[inp[i].second]-1);

    return ret;
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