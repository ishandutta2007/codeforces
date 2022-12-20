#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

long long k;

long long mx[nmax];

void solve()
{
    scanf("%i%lld",&n,&k);

    mx[0]=1;
    mx[1]=1;
    for(int i=2;i<=n;i++)
        mx[i]=min(mx[i-1]*2,k+1);

    if(mx[n]<k)
    {
        printf("-1\n");
        return;
    }

    int i=1;

    while(i<=n)
    {
        if(mx[n-i]>=k)
        {
            printf("%i ",i);
            i++;
            continue;
        }
        else
        {
            int l=i;

            while(mx[n-i]<k)
            {
                k=k-mx[n-i];
                i++;
            }

            for(int j=i;j>=l;j--)printf("%i ",j);

            i++;
        }
    }
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