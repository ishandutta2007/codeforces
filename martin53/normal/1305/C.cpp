#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n,m,inp[nmax];
int main()
{
    scanf("%i%i",&n,&m);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    if(n>m)
    {
        printf("0\n");
        return 0;
    }

    long long prod=1;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            prod=prod*abs(inp[i]-inp[j])%m;
    printf("%lld\n",prod);
    return 0;
}