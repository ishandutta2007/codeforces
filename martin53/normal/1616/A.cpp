#include<bits/stdc++.h>
using namespace std;

int solve()
{
    int n;
    scanf("%i",&n);

    set<int> active={};

    for(int i=1;i<=n;i++)
    {
        int cur;
        scanf("%i",&cur);

        if(active.count(cur))active.insert(-cur);
        else active.insert(cur);
    }

    return active.size();
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