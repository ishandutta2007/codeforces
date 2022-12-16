#include<bits/stdc++.h>
using namespace std;

int solve()
{
    int ret=0;

    int n;
    scanf("%i",&n);
    for(int i=1;i<=n;i++)
    {
        int cur;
        scanf("%i",&cur);
        ret=max(ret,cur-i);
    }

    return ret;
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