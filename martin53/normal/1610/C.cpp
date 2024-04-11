#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;
int n;
pair<int,int> inp[nmax];

bool can(int cur)
{
    pair<int,int> now={cur-1,0};

    for(int i=1;i<=n;i++)
        if(now.first<=inp[i].first&&now.second<=inp[i].second)now.first--,now.second++;

    return now.first<0;
}

int solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i%i",&inp[i].first,&inp[i].second);

    int ok=0,not_ok=n+1;
    while(not_ok-ok>1)
    {
        int av=(ok+not_ok)/2;
        if(can(av))ok=av;
        else not_ok=av;
    }
    return ok;
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