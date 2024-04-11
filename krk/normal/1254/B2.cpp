#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;
const ll Inf = 9000000000000000000ll;

int n;
int a[Maxn];
ll s;
ll res = Inf;

void Check(ll i)
{
    ll cand = 0;
    ll got = 0;
    for (int j = 0; j + 1 < n; j++) {
        got += a[j];
        cand += min(got % i, (s - got) % i);
    }
    res = min(res, cand);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        s += a[i];
    }
    ll num = s;
    for (ll i = 2; i * i <= num; i++) if (num % i == 0) {
        Check(i);
        while (num % i == 0) num /= i;
    }
    if (num > 1) Check(num);
    printf("%I64d\n", res >= Inf? -1ll: res);
    return 0;
}