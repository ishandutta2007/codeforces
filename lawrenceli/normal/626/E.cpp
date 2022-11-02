#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 200100;

int n, x[maxn];
ll p[maxn];
ld ans = -1e18;
int l1, r1, l2, r2;

ld val(int i, int k) {
    return ld(p[i + 1] - p[i - k] + p[n] - p[n - k]) / (1 + 2 * k) - x[i];
}

ld val2(int i, int k) {
    return ld(p[i + 2] - p[i - k] + p[n] - p[n - k]) / (2 + 2 * k) - ld(x[i] + x[i + 1]) / 2;
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i];
    sort(x, x + n);
    for (int i = 0; i < n; i++) p[i + 1] = p[i] + x[i];

    for (int i = 0; i < n; i++) {
        int lo = 0, hi = min(i, n - 1 - i);
        while (hi - lo > 5) {
            int m1 = lo + (hi - lo) / 3, m2 = lo + 2 * (hi - lo) / 3;
            if (val(i, m1) < val(i, m2)) lo = m1;
            else hi = m2;
        }

        for (int j = lo; j <= hi; j++)
            if (val(i, j) > ans)
                ans = val(i, j), l1 = i - j, r1 = i + 1, l2 = n - j, r2 = n;
    }

    for (int i = 0; i < n - 1; i++) {
        int lo = 0, hi = min(i, n - 2 - i);
        while (hi - lo > 5) {
            int m1 = lo + (hi - lo) / 3, m2 = lo + 2 * (hi - lo) / 3;
            if (val2(i, m1) < val2(i, m2)) lo = m1;
            else hi = m2;
        }

        for (int j = lo; j <= hi; j++)
            if (val2(i, j) > ans)
                ans = val2(i, j), l1 = i - j, r1 = i + 2, l2 = n - j, r2 = n;
    }

    cout << r1 - l1 + r2 - l2 << '\n';
    for (int i = l1; i < r1; i++) cout << x[i] << ' ';
    for (int i = l2; i < r2; i++) cout << x[i] << ' ';
}