#include<bits/stdc++.h>
using namespace std;

int need[31];

int solve()
{
    memset(need,0,sizeof(need));

    int n,k;
    scanf("%i%i",&n,&k);

    for(int i=1;i<=n;i++)
    {
        int cur;
        scanf("%i",&cur);

        for(int j=0;j<=30;j++)
            if((cur&(1<<j))==0)need[j]++;
    }

    int outp=0;

    for(int j=30;j>=0;j--)
        if(k>=need[j])
        {
            k=k-need[j];
            outp+=(1<<j);
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