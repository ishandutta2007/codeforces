#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;
typedef pair <ii, ll> iill;

const int Maxn = 105;

int n;
iill a[Maxn];

bool Less(const iill &a, const iill &b)
{
    if (a.first.first != b.first.first) return a.first.first < b.first.first;
    return a.first.second > b.first.second;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        ll x; scanf("%I64d", &x);
        a[i].second = x;
        while (x % 2 == 0) { a[i].first.first++; x /= 2; }
        while (x % 3 == 0) { a[i].first.second++; x /= 3; }
    }
    sort(a, a + n, Less);
    for (int i = 0; i < n; i++)
        printf("%I64d%c", a[i].second, i + 1 < n? ' ': '\n');
    return 0;
}