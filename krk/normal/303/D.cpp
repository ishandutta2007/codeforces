#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, x;
vector <int> primes;
int mod;

bool Prime(int x)
{
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0) return false;
    return true;
}

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

bool Check(int cand)
{
    for (int i = 0; i < primes.size(); i++)
        if (toPower(cand, (mod - 1) / primes[i]) == 1)
            return false;
    return true;
}

int main()
{
    scanf("%d %d", &n, &x); x--;
    if (n == 1) { printf("%d\n", x > 1? x: -1); return 0; }
    mod = n + 1;
    if (!Prime(mod)) { printf("-1\n"); return 0; }
    int cur = mod - 1;
    for (int i = 2; i * i <= cur; i++)
        if (cur % i == 0) {
            primes.push_back(i);
            while (cur % i == 0) cur /= i;
        }
    if (cur > 1) primes.push_back(cur);
    while (x > 1 && !Check(x % mod)) x--;
    printf("%d\n", x > 1? x: -1);
    return 0;
}