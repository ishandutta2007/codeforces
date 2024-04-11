#include<bits/stdc++.h>
using namespace std;

map<int,int> seen;
int solve()
{
    seen={};

    int outp=-1;

    int n;
    scanf("%i",&n);

    for(int i=1;i<=n;i++)
    {
        int cur;
        scanf("%i",&cur);

        if(seen.count(cur))
        {
            outp=max(outp,n-(i-seen[cur]));
        }

        seen[cur]=i;
    }

    return outp;
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