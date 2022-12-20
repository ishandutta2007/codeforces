#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
long long n;
int main()
{
    scanf("%lld",&n);

    for(long long i=2;i*i<=n;i++)
        if(n%i==0)
        {
            while(n%i==0)n=n/i;
            if(n==1)
            {
                printf("%lld\n",i);
                exit(0);
            }
            else
            {
                printf("1\n");
                exit(0);
            }
        }

    printf("%lld\n",n);
    return 0;
}