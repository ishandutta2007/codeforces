#include <bits/stdc++.h>

using namespace std;

int n;
int a[100005];
int b[100005];
int m;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    long long all = 1ll * n * n;
    for (int i = 1; i <= n; ++i) {
        int sz; cin >> sz;
        vector <int> v(sz);
        for (int j = 0; j < sz; ++j) cin >> v[j];
        int flg = 1;
        for (int j = 0; j + 1 < sz; ++j) if (v[j] < v[j+1]) flg = 0;
        if (!flg) continue;
        ++m;
        a[m] = v[0];
        b[m] = v[sz-1];
    }
    sort(a + 1, a + m + 1);
    for (int i = 1; i <= m; ++i) all -= upper_bound(a + 1, a + m + 1, b[i]) - a - 1;
    cout << all << endl;
    return 0;
}