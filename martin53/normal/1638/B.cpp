#include<bits/stdc++.h>
using namespace std;

bool solve()
{
    bool ok=1;

    int prv[2]={-1,-1};

    int n;

    scanf("%i",&n);

    for(int i=1;i<=n;i++)
    {
        int cur;

        scanf("%i",&cur);

        if(prv[cur%2]>cur)ok=0;

        prv[cur%2]=cur;
    }

    return ok;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        if(solve())printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}