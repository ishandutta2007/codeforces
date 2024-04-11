#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;
int n,inp[nmax];

int solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    int outp=0,lq=0,rq=n+1;
    long long sum=0;

    while(rq-lq>1)
    {
        if(sum>0)
        {
            rq--;
            sum=sum-inp[rq];
        }
        else if(sum<0)
        {
            lq++;
            sum=sum+inp[lq];
        }
        else
        {
            outp=max(outp,lq+n+1-rq);
            lq++;
            sum=sum+inp[lq];
        }
    }

    if(sum==0)outp=n;

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