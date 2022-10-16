#include <bits/stdc++.h>

using namespace std;

int n, k;
long long a[100005];

long long s(int i, int j) {
    long long ret = 0, c;
    cout << "or " << i << ' ' << j << endl;
    cin >> c; ret += c;
    cout << "and " << i << ' ' << j << endl;
    cin >> c; ret += c;
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    long long x = s(1, 2);
    long long y = s(2, 3);
    long long z = s(1, 3);
    long long t = (x + y + z) / 2;
    a[1] = t - y, a[2] = t - z, a[3] = t - x;
    for (int i = 4; i <= n; ++i) a[i] = s(1, i) - a[1];
    sort(a + 1, a + n + 1);
    cout << "finish " << a[k] << endl;
    return 0;
}