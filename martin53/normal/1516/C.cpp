#include<bits/stdc++.h>
using namespace std;

const int nmax=1e2+42,MX=100*2000+42;

int n,inp[nmax];

bitset<MX> seen;

int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    int g=0;
    for(int i=1;i<=n;i++)g=__gcd(g,inp[i]);

    for(int i=1;i<=n;i++)inp[i]=inp[i]/g;

    int sum=0;
    for(int i=1;i<=n;i++)sum+=inp[i];

    seen[0]=1;
    for(int i=1;i<=n;i++)
        seen=seen|(seen<<inp[i]);

    if(sum%2||seen[sum/2]==0)
    {
        printf("0\n");
        return 0;
    }
    else
    {
        for(int i=1;i<=n;i++)
            if(inp[i]%2==1)
            {
                printf("1\n%i\n",i);
                return 0;
            }
    }

    return 0;
}