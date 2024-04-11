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

int simple(deque<int> a, deque<int> b) {
    if (b.back() == 0) return -1;
    int n = (int)a.size();
    for (int x = b.back(), i = n - 1; i >= 0; i--, x--) {
        if (b[i] != x) return -1;
        if (x == 1) break;
    }
    int res = 0;
    multiset<int> q(a.begin(), a.end());
    while (b.back() != n) {
        int x = b.back() + 1;
        if (!q.count(x)) {
            return -1;
        }
        q.erase(q.lower_bound(x));
        q.insert(b.front());
        b.push_back(x);
        b.pop_front();
        res++;
    }
    return res;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    deque<int> a(n), b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int res = simple(a, b);

    if (res != -1) {
        cout << res << "\n";
        return 0;
    }

    vector<int> s(n + 1, inf);

    for (int i = 0; i < n; i++) {
        s[a[i]] = 0;
    }

    for (int i = 0; i < n; i++) {
        s[b[i]] = i + 1;
    }

    int t = -inf;

    for (int i = 1; i <= n; i++) {
        t = max(t, s[i] - (i - 1));
    }

    cout << t + n << "\n";

    return 0;
}