#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;
int n,m,k;

int out[nmax];

bool solve()
{
    scanf("%i%i%i",&n,&k,&m);

    for(int i=1;i<=n;i++)out[i]=1;

    for(int i=1;i<=m;i++)
    {
        int val;
        scanf("%i",&val);
        out[val]=0;
    }

    if((n-m)%(k-1))return 0;

    int sum=0;
    for(int i=1;i<=n;i++)
    {
        if(out[i]==0)
        {
            if(sum>=(k-1)/2&&n-m-sum>=(k-1)/2)return 1;
        }

        sum+=out[i];
    }

    return 0;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        if(solve())printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}