#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;

    scanf("%i",&n);

    map<int,int> mp={};

    for(int i=1;i<=n;i++)
    {
        int cur;

        scanf("%i",&cur);

        mp[cur]++;
    }

    for(int i=0;mp[i];i++)
    {
        printf("%i ",i);
        mp[i]--;
    }

    for(auto w:mp)
    {
        for(int j=0;j<w.second;j++)printf("%i ",w.first);
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