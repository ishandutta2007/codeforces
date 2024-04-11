#include<bits/stdc++.h>
using namespace std;

const int nmax=5e3+42;

int n,inp[nmax];

int pref[nmax][nmax];

long long solve()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)pref[i][j]=pref[i-1][j];

        for(int j=inp[i];j<=n;j++)pref[i][j]++;
    }

    long long outp=0;

    for(int b=1;b<=n;b++)
        for(int c=b+1;c<=n;c++)
        {
            int cnt_a=pref[b-1][inp[c]];
            int cnt_d=pref[n][inp[b]]-pref[c][inp[b]];

            //cout<<b<<" "<<c<<" -> "<<cnt_a<<" "<<cnt_d<<endl;

            outp+=cnt_a*cnt_d;
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

        printf("%lld\n",solve());
    }

    return 0;
}