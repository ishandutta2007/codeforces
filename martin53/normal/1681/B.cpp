#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

int solve()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    long long sum=1;

    int m;
    scanf("%i",&m);

    for(int i=1;i<=m;i++)
    {
        int cur;
        scanf("%i",&cur);

        sum+=cur;
    }

    sum=sum%n;
    if(sum==0)sum=n;

    return inp[sum];
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