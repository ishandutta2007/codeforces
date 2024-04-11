#include<bits/stdc++.h>
using namespace std;

void solve()
{
    set<int> seen={};

    int n;
    scanf("%i",&n);

    for(int i=1;i<=n;i++)
    {
        int cur;
        scanf("%i",&cur);

        seen.insert(cur);
    }

    for(int k=1;k<=n;k++)
    {
        int score=seen.size();
        score=max(score,k);

        printf("%i ",score);
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