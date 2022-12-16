#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;
int n,k;

pair<int,int> inp[nmax];



void solve()
{
    scanf("%i%i",&n,&k);
    for(int i=1;i<=n;i++)scanf("%i%i",&inp[i].first,&inp[i].second);

    for(int i=1;i<=n;i++)
    {
        bool ok=1;

        for(int j=1;j<=n;j++)
        {
            int cur=abs(inp[i].first-inp[j].first)+abs(inp[i].second-inp[j].second);

            if(cur>k)ok=0;
        }

        if(ok)
        {
            printf("1\n");
            return;
        }
    }
    printf("-1\n");
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