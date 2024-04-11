#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

int solve()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    int mini=1,maxi=1;

    for(int i=2;i<=n;i++)
    {
        if(inp[i]>inp[maxi])maxi=i;
        if(inp[i]<inp[mini])mini=i;
    }

    int p=min(maxi,mini),q=max(maxi,mini);

    return n-max(max(p-1,n-q),q-p-1);
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