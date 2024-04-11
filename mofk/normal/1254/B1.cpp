#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000006;
int n;
int a[maxn];
vector <int> v;

long long cost(int p) {
    long long ret = 0;
    for (int i = 0; i < v.size(); i += p) {
        int median = v[(i + i + p - 1) / 2];
        for (int j = i; j < i + p; ++j)
            ret += abs(v[j] - median);
    }
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] == 1) v.push_back(i);
    }
    if (v.size() == 1) {
        cout << -1 << endl;
        return 0;
    }
    long long ans = 1e18;
    int tmp = v.size(), p = 2;
    while (p * p <= tmp) {
        if (tmp % p == 0) {
            ans = min(ans, cost(p));
            while (tmp % p == 0)
                tmp /= p;
        }
        ++p;
    }
    if (tmp > 1)
        ans = min(ans, cost(tmp));
    cout << ans << endl;
    return 0;
}