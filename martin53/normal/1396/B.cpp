#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;

int n,inp[nmax],outp[nmax];

bool solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    sort(inp+1,inp+n+1);

    int sum=0;

    for(int i=1;i<=n;i++)
        sum+=inp[i];

    if(sum%2==0&&sum-inp[n]>=inp[n])return 0;
    return 1;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;
        if(solve())printf("T\n");
        else printf("HL\n");
    }

    return 0;
}