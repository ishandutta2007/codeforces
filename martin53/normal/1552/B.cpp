#include<bits/stdc++.h>
using namespace std;

const int nmax=5e4+42;

int n,inp[nmax][5];

int who(int a,int b)
{
    int cnt[2]={0,0};

    for(int j=0;j<5;j++)
        cnt[inp[a][j]<inp[b][j]]++;

    if(cnt[1]>=3)return a;
    return b;
}

int solve()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)
        for(int j=0;j<5;j++)scanf("%i",&inp[i][j]);

    int winner=1;

    for(int i=2;i<=n;i++)
        winner=who(winner,i);

    for(int i=1;i<=n;i++)
        if(winner!=i&&who(winner,i)!=winner)return -1;

    return winner;
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