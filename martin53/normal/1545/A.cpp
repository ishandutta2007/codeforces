#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n;

pair<int,int> inp[nmax];

bool solve()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i].first);
        inp[i].second=i;
    }

    sort(inp+1,inp+n+1);

    /*
    for(int i=1;i<=n;i++)
        cout<<i<<" -> "<<inp[i].first<<" "<<inp[i].second<<endl;
    */

    for(int i=1;i<=n;i++)
    {
        int j=i;

        int need[2]={0,0};

        while(j<=n&&inp[i].first==inp[j].first)
        {
            need[j%2]++;

            need[inp[j].second%2]--;

            j++;
        }

        if(need[0]||need[1])return 0;

        i=j-1;
    }

    return 1;
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