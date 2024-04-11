#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n + 1), p(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        p[i] = p[i - 1] ^ a[i];

    const int K = 50;
    int res = inf;
    for (int le = 1; le <= K; le++) {
        for (int ri = 1; ri <= K && le + ri <= n; ri++) {
            for (int i = le; i + ri <= n; i++) {
                if ((p[i] ^ p[i - le]) > (p[i + ri] ^ p[i]))
                    res = min(res, le + ri - 2);
            }
        }
    }

    if (res == inf)
        res = -1;

    cout << res << "\n";

    return 0;
}