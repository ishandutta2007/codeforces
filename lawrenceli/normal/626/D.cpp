#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef long double ld;

const int maxn = 2005;
const int maxa = 5005;

int n, a[maxn];
ld p[maxa], q[maxa];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            p[a[j] - a[i]] += 2. / n / (n - 1);

    for (int i = 1; i < maxa; i++)
        q[i] = q[i - 1] + p[i];

    ld ans = 0;
    for (int i = 0; i < maxa; i++)
        for (int j = 0; j < maxa; j++)
            if (i + j < maxa)
                ans += p[i] * p[j] * (1 - q[i + j]);

    cout << fixed << setprecision(10) << ans << '\n';
}