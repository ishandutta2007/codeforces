#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int chk[1000005];
vector <long long> pr;
long long a, b, c, ans = 0;

void sieve()
{
    for (int i = 2; i <= 1e3; i++)
        if (chk[i] == 0)
            for (int j = i; j <= 1e6 / i; j++)
                chk[i * j] = i;
}

void fact()
{
    long long t = a;
    for (int i = 2; i <= 1e6; i++)
        if (chk[i] == 0 && t % i == 0)
        {
            pr.push_back(i);
            do
            {
                t /= i;
            } while (t % i == 0);
        }
    if (t != 1)
        pr.push_back(t);
}

int main()
{
    sieve();
    scanf("%I64d%I64d", &a, &b);
    fact();
    while (b % a != 0)
    {
        c = __gcd(a, b); a /= c; b /= c;
        long long t = 0;
        for (int i = 0; i < pr.size(); i++)
            if (a % pr[i] == 0)
                t = max(t, b / pr[i] * pr[i]);
        ans += b - t; b = t;
    }
    printf("%I64d", ans + b / a);
}