#include<bits/stdc++.h>
using namespace std;

vector< pair<int,int> > primes;
vector<int> high;

void solve()
{
    primes={};
    high={};

    long long p,q;

    scanf("%lld%lld",&p,&q);

    if(p%q)
    {
        printf("%lld\n",p);
        return;
    }

    long long outp=1;

    for(int i=2;i*i<=q;i++)
        if(q%i==0)
        {
            long long cur_p=p;
            while(cur_p%i==0)cur_p=cur_p/i;

            long long mult=1;
            while(q%i==0)
            {
                q=q/i;
                mult=mult*i;
            }

            mult=mult/i;

            outp=max(outp,cur_p*mult);
        }
    if(q!=1)
    {
        int i=q;

            long long cur_p=p;
            while(cur_p%i==0)cur_p=cur_p/i;

            long long mult=1;
            while(q%i==0)
            {
                q=q/i;
                mult=mult*i;
            }

            mult=mult/i;

            outp=max(outp,cur_p*mult);
    }

    printf("%lld\n",outp);
}

int main()
{
    int t;
    scanf("%i",&t);
    while(t)
    {
        t--;
        solve();
    }
    return 0;
}