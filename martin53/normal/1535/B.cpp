#include<bits/stdc++.h>
using namespace std;

bool cmp(int a,int b)
{
    return a%2<b%2;
}

const int nmax=1e5+42;

int n,inp[nmax];

void solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    sort(inp+1,inp+n+1,cmp);

    int outp=0;

    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(__gcd(inp[i],2*inp[j])>1)outp++;

    printf("%i\n",outp);
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