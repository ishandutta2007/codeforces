#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

const long long mod = 1000000007;
int N,M,K;

long long fact(long long v)
{
    long long r = 1;
    while (v) r = (r * v--) % mod;
    return r;
}

long long inv(long long v)
{
    long long r = 1, p = mod-2;
    while (p){
        if (p&1) r = (r * v) % mod;
        v = (v * v) % mod; p >>= 1;
    }
    return r;
}

long long C(int n, int m)
{
    if (m < 0 || m > n) return 0;
    return fact(n) * inv(fact(m)) % mod * inv(fact(n-m)) % mod;
}

int main()
{
    scanf ("%d %d %d",&N,&M,&K);
    long long ans = C(N-1,2*K) * C(M-1,2*K) % mod;
    printf ("%lld",ans);

    return 0;
}