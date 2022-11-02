#include<bits/stdc++.h>
#define int long long
using namespace std;
int t, n, i, j, k, a, b, A[200010];
main()
{
    for(scanf("%lld", &t);t--;)
    {
        scanf("%lld", &n);
        a=2;
        while(a<n)a*=4;
        if(a==n)puts("Bob");
        else if(n%2==1)puts("Bob");
        else puts("Alice");
    }
}