#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int n,q,inp[nmax];

vector< pair<long long/*sum*/,int/*id*/> > active;

void solve()
{
    scanf("%i%i",&n,&q);

    long long sum=0;

    active={{0,0}};

    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);

        sum+=inp[i];

        if(sum>active.back().first)
        {
            active.push_back({sum,i});
        }
    }

    for(int i=1;i<=q;i++)
    {
        int x;
        scanf("%i",&x);

        long long add=0;

        if(sum<=0)
        {
            if(active.back().first<x)
            {
                printf("-1 ");
                continue;
            }

        }
        else
        {
            long long u=x-active.back().first;

            if(u>=0)
            {
                add=(u+sum-1)/sum*n;

                x=x-(u+sum-1)/sum*sum;
            }
        }

        int ok=active.size()-1,not_ok=-1;
        while(ok-not_ok>1)
        {
            int av=(ok+not_ok)/2;
            if(active[av].first>=x)ok=av;
            else not_ok=av;
        }

        printf("%lld ",add+active[ok].second-1);
    }
    printf("\n");
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