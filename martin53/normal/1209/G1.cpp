#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int n,q;

int inp[nmax],last[nmax],cnt[nmax];

int solve()
{
    int outp=n,ri=0,mx=0;

    for(int i=1;i<=n;i++)
    {
        ri=max(ri,last[inp[i]]);
        mx=max(mx,cnt[inp[i]]);

        if(ri==i)
        {
            outp=outp-mx;
            mx=0;
        }
    }
    return outp;
}

int main()
{
    scanf("%i%i",&n,&q);

    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);
        last[inp[i]]=i;
        cnt[inp[i]]++;
    }

    printf("%i\n",solve());
    return 0;
}