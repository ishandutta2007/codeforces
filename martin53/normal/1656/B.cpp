#include<bits/stdc++.h>
using namespace std;

bool solve()
{
    set<int> in={};

    int n,k;
    scanf("%i%i",&n,&k);

    bool ok=0;

    for(int i=1;i<=n;i++)
    {
        int cur;
        scanf("%i",&cur);

        if(in.count(cur+k)||in.count(cur-k))ok=1;

        in.insert(cur);
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
}