#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int n,m;
long long a[nmax],b[nmax];

int main()
{
    scanf("%i%i",&n,&m);

    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);

    long long g=0;
    for(int i=2;i<=n;i++)g=__gcd(g,abs(a[i]-a[i-1]));

    for(int i=1;i<=m;i++)
    {
        long long cur;
        scanf("%lld",&cur);
        printf("%lld ",__gcd(g,cur+a[1]));
    }

    printf("\n");

    return 0;
}