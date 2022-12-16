#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int cnt[20][nmax];

int solve()
{
    int l,r;
    scanf("%i%i",&l,&r);

    int ret=0;
    for(int j=0;j<20;j++)
    {
        ret=max(ret,cnt[j][r]-cnt[j][l-1]);
    }

    return r-l+1-ret;
}

int main()
{
    for(int i=1;i<=nmax;i++)
        for(int j=0;j<20;j++)
            if((i&(1<<j)))cnt[j][i]=cnt[j][i-1]+1;
            else cnt[j][i]=cnt[j][i-1];

    int t;
    scanf("%i",&t);


    while(t)
    {
        t--;
        printf("%i\n",solve());
    }

    return 0;
}