#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

int solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    int from=-1,to=-1;

    for(int i=1;i<n;i++)
        if(inp[i]==inp[i+1])
        {
            from=i;
            break;
        }

    for(int i=n;i>1;i--)
        if(inp[i]==inp[i-1])
        {
            to=i;
            break;
        }

    int diff=to-from;

    if(diff<=1)return 0;

    if(diff==2)return 1;

    return diff-2;
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