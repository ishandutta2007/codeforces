#include<bits/stdc++.h>
using namespace std;

const int nmax=4e6+42;

int n;

pair<int,int> inp[nmax];

int solve()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)
    {
        int sz;
        scanf("%i",&sz);

        int need=0;

        for(int j=1;j<=sz;j++)
        {
            int cur;
            scanf("%i",&cur);

            need=max(need,cur-j+1);
        }

        inp[i]={need+1,sz};
    }

    sort(inp+1,inp+n+1);

    int outp=0,sum=0;

    for(int i=1;i<=n;i++)
    {
        outp=max(outp,inp[i].first-sum);
        sum+=inp[i].second;
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