#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,x,inp[nmax];

bool hand()
{
    for(int i=2;i<=n;i++)
        if(inp[i-1]>inp[i])return 0;

    return 1;
}

bool solve()
{
    scanf("%i%i",&n,&x);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    if(x>n-1)return hand();

    vector<int> free={};
    for(int i=1;i<=n;i++)
        if(i-1>=x||n-i>=x)free.push_back(inp[i]);

    sort(free.begin(),free.end());

    int pointer=0;
    for(int i=1;i<=n;i++)
        if(i-1>=x||n-i>=x)
            inp[i]=free[pointer++];

    return hand();
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