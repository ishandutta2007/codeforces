#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

bool test(int cur)
{
    int l=1,r=n;

    while(l<r)
    {
        if(inp[l]==inp[r])
        {
            l++;
            r--;
        }
        else if(inp[l]==cur)l++;
        else if(inp[r]==cur)r--;
        else return 0;
    }

    return 1;
}

bool solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=1;i<=n+1-i;i++)
        if(inp[i]!=inp[n+1-i])return test(inp[i])||test(inp[n+1-i]);

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