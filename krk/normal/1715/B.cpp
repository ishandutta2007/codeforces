#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int T;
int n;
ll k, b, s;
ll a[Maxn];

bool Solve()
{
    if (s < k * b) return false;
    fill(a, a + n, 0ll);
    a[0] = k * b; s -= k * b;
    if (s > n * (k - 1)) return false;
    for (int i = 0; i < n; i++) {
        ll mn = min(s, k - 1);
        a[i] += mn; s -= mn;
    }
    return true;
}

int main()
{
    cin >> T;
    while (T--) {
        cin >> n >> k >> b >> s;
        if (Solve())
            for (int i = 0; i < n; i++)
                printf("%I64d%c", a[i], i + 1 < n? ' ': '\n');
        else printf("-1\n");
    }
    return 0;
}