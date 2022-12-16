#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax],outp[nmax];

bool in[nmax];

bool solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=0;i<n;i++)in[i]=0;

    for(int i=1;i<=n;i++)
    {
        int cur=(i-1+inp[i])%n;
        cur=(cur+n)%n;

        if(in[cur])return 0;
        in[cur]=1;
    }

    return 1;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        if(solve())printf("YES\n");
        else printf("NO\n");
        t--;
    }
    return 0;
}