#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax],seen[nmax];

int solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    sort(inp+1,inp+n+1);

    int outp=n;
    for(int i=1;i<=n;i++)seen[i]=0;

    int pointer=1;

    for(int i=1;i<=n;i++)
        if(inp[i]<=n&&seen[inp[i]]==0)
        {
            seen[inp[i]]=1;
            outp--;
        }
        else
        {
            while(seen[pointer])pointer++;

            if(2*pointer<inp[i])seen[pointer]=1;
            else return -1;
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