#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

void print(int val)
{
    if(val<0)printf("%i\n",n);
    else printf("%i\n",n-1);

    for(int i=1;i<=n;i++)
        if(i!=val)printf("%i ",i);

    printf("\n");
}

bool prime(int num)
{
    for(int i=2;i*i<=num;i++)
        if(num%i==0)return 0;

    return 1;
}

void solve()
{
    scanf("%i",&n);

    int sum=0;

    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);
        sum+=inp[i];
    }

    if(prime(sum)==0)print(-1);
    else
    {
        for(int j=1;j<=n;j++)
            if(inp[j]%2)
            {
                print(j);
                break;
            }
    }
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