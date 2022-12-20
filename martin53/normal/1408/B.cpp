#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,k,inp[nmax];

void solve()
{
    scanf("%i%i",&n,&k);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    if(k==1)
    {
        if(inp[1]==inp[n])printf("1\n");
        else printf("-1\n");
        return;
    }

    int outp=0;
    while(inp[n])
    {
        outp++;

        int diff=0,prv=-1;

        for(int j=1;j<=n;j++)
            if(inp[j]==prv)inp[j]=0;
            else
            {
                if(diff<k)
                {
                    diff++;
                    prv=inp[j];
                }

                inp[j]=inp[j]-prv;
            }
    }

    printf("%i\n",outp);
}

int main()
{
    int t;

    scanf("%i",&t);

    while(t)
    {
        solve();
        t--;
    }
    return 0;
}