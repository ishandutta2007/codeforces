#include<bits/stdc++.h>
using namespace std;

int solve()
{
    map<int,int> seen={};

    int n,w;

    scanf("%i%i",&n,&w);

    for(int i=1;i<=n;i++)
    {
        int cur;
        scanf("%i",&cur);
        seen[cur]++;
    }

    int outp=0;

    for(int go=1;n;go++)
    {
        outp++;

        int cur=w;

        for(int j=(1<<20);j>=1;j=j/2)
        {
            int take=min(cur/j,seen[j]);

            n=n-take;
            seen[j]=seen[j]-take;
            cur=cur-take*j;
        }
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