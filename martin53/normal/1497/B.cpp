#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,m,inp[nmax];

int cnt[nmax];

int solve()
{
    scanf("%i%i",&n,&m);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=0;i<=m;i++)cnt[i]=0;

    for(int i=1;i<=n;i++)cnt[inp[i]%m]++;

    int outp=n;

    if(m%2==0&&cnt[m/2])outp=outp-(cnt[m/2]-1);
    if(cnt[0])outp=outp-(cnt[0]-1);

    for(int i=1;i+i<m;i++)
    {
        int p=cnt[i];
        int q=cnt[m-i];

        if(p==q&&p)outp=outp-p-(q-1);
        else outp=outp-2*min(p,q);
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