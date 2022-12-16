#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42;

int n,inp[nmax];

int find_dvd(int val,int l,int r)
{
    for(int i=1;i<=val;i++)
        if(val%i==0)
        {
            if(l<=i&&i<=r)return i;

            if(l<=val/i&&val/i<=r)return val/i;
        }
    return 1;
}
void solve()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    long long sum[2]={0,0};

    for(int i=1;i<=n;i++)
        sum[i%2]+=inp[i];

    int which=0;

    if(sum[0]>sum[1])which=1;

    for(int i=1;i<=n;i++)
        if(i%2==which)inp[i]=1;

    for(int i=1;i<=n;i++)printf("%i ",inp[i]);
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