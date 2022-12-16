#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int pref[nmax];

void solve()
{
    int n;

    scanf("%i",&n);

    for(int i=1;i<=n;i++)pref[i]=0;

    for(int i=1;i<=n;i++)
    {
        int cur;

        scanf("%i",&cur);

        int l=max(1,i-cur+1);

        pref[l]++;
        pref[i+1]--;
    }

    for(int i=1;i<=n;i++)
    {
        pref[i]=pref[i]+pref[i-1];

        if(pref[i])printf("1 ");
        else printf("0 ");
    }

    printf("\n");
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