#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n;
int cnt[nmax];

priority_queue<int> pq,idle;

void solve()
{
    pq=idle;

    scanf("%i",&n);

    for(int i=0;i<=n;i++)cnt[i]=0;

    for(int i=1;i<=n;i++)
    {
        int cur;
        scanf("%i",&cur);
        cnt[cur]++;
    }

    bool broken=0;
    long long help=0;

    for(int i=0;i<=n;i++)
    {
        if(broken){printf("-1 ");continue;}
        else
        {
            long long outp=cnt[i]+help;

            printf("%lld ",outp);
        }

        for(int j=0;j<cnt[i];j++)
        {
            pq.push(i);
        }

        if(pq.size()==0)broken=1;
        else
        {
            help+=i-pq.top();
            pq.pop();
        }
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