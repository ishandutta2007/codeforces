#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;

    vector<int> pr(m), sf(m);

    for (int j = 0, i = 0; i < m; i++) {
        while (a[j] != b[i])
            j++;
        pr[i] = j++;
    }
    for (int j = n - 1, i = m - 1; i >= 0; i--) {
        while (a[j] != b[i])
            j--;
        sf[i] = j--;
    }

    int res = 0;
    for (int i = 0; i + 1 < m; i++) {
        res = max(res, sf[i + 1] - pr[i]);
    }

    cout << res << "\n";

    return 0;
}