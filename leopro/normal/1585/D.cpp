#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

#define YES {cout << "YES\n";return;};
#define NO {cout << "NO\n";return;};

bool isSorted(vector<int> a) {
    for (int i = 1; i < a.size(); ++i) if (a[i - 1] > a[i]) return false;
    return true;
}

struct SumTree {
    int n;
    vector<int> sm;

    SumTree(int n) : n(n), sm(2 * n, 0) {}

    void set(int i, int x) {
        i += n;
        sm[i] = x;
        i /= 2;
        while (i > 0) {
            sm[i] = sm[2 * i] + sm[2 * i + 1];
            i /= 2;
        }
    }

    int get(int l, int r) {
        int x = 0;
        for (l += n, r += n; l < r; l /= 2, r /= 2) {
            if (l & 1) x += sm[l++];
            if (r & 1) x += sm[--r];
        }
        return x;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    if (isSorted(a)) YES
    if (n <= 2) NO
    SumTree st(n + 1);
    vector<int> d = a;
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    if (d.size() < n) YES
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        st.set(a[i], 1);
        cnt ^= st.get(a[i] + 1, n + 1);
    }
    if (cnt & 1) NO
    YES
}