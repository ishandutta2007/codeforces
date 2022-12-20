#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42;

int n,k;
pair<int,int> inp[nmax];

bool solve()
{
    scanf("%i%i",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i].first);
        inp[i].second=i;
    }

    sort(inp+1,inp+n+1);

    int ret=1;

    for(int i=2;i<=n;i++)
        if(inp[i-1].second!=inp[i].second-1)ret++;

    //cout<<"ret= "<<ret<<endl;

    return ret<=k;
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