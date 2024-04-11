#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
ll a, b, x;

bool Solve(ll a, ll b, ll x)
{
    if (a > b) swap(a, b);
    if (a == x || b == x) return true;
    if (x > b) return false;
    if (a == 0) return false;
    if (x > a) return b % a == x % a;
    return Solve(b % a, a, x);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%I64d %I64d %I64d", &a, &b, &x);
        printf("%s\n", Solve(a, b, x)? "YES": "NO");
    }
    return 0;
}