#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n, q;
    cin >> n >> q;

    deque<int> a(n);

    int m = n;

    vector<pii> ans(m);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        int A = a.front();
        a.pop_front();
        int B = a.front();
        a.pop_front();
        ans[i] = {A, B};
        if (A < B) swap(A, B);
        a.push_front(A);
        a.push_back(B);
    }

    int mx = a.front();

    a.pop_front();

    for (int iter = 0; iter < q; iter++) {
        ll t;
        cin >> t;
        t--;
        if (t < m) {
            cout << ans[t].first << " " << ans[t].second << "\n";
        } else {
            t -= m;
            t %= (n - 1);
            cout << mx << " " << a[t] << "\n";
        }
    }

    return 0;
}