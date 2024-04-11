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

int rec(const string& s, const string& a, vector<int>& used_in_a, vector<int>& perm, int i, int k) {
    int n = (int) a.size();
    if (i == n) return n;

    int ai = a[i] - 'a';
    int si = s[i] - 'a';

    if (perm[si] != -1) {
        if (perm[si] < ai) {
            return -1;
        } else if (perm[si] > ai) {
            return i;
        } else {
            return rec(s, a, used_in_a, perm, i + 1, k);
        }
    }

    int c = ai + 1;
    while (c < k && used_in_a[c]) c++;

    if (used_in_a[ai]) {
        if (c == k) return -1;
        used_in_a[c] = 1;
        perm[si] = c;
        return i;
    }

    used_in_a[ai] = 1;
    perm[si] = ai;

    int lcp = rec(s, a, used_in_a, perm, i + 1, k);
    if (lcp != -1) return lcp;

    used_in_a[ai] = 0;
    perm[si] = -1;

    if (c == k) {
        return -1;
    }

    used_in_a[c] = 1;
    perm[si] = c;

    return i;
}

void solve() {
    int k;
    cin >> k;
    string s, a, b;
    cin >> s >> a >> b;
    int n = (int) s.size();

    vector<int> used_in_a(k);
    vector<int> perm(k, -1);

    int lcp = rec(s, a, used_in_a, perm, 0, k);

    for (int i = lcp + 1; i < n; i++) {
        int si = s[i] - 'a';
        if (perm[si] != -1) continue;
        int c = 0;
        while (c < k && used_in_a[c]) c++;
        if (c == k) {
            cout << "NO\n";
            return;
        }
        used_in_a[c] = 1;
        perm[si] = c;
    }

    for (int i = 0; i < k; i++) {
        if (perm[i] != -1) continue;
        int c = 0;
        while (used_in_a[c]) c++;
        used_in_a[c] = 1;
        perm[i] = c;
    }

    for (int i = 0; i < n; i++) {
        s[i] = 'a' + perm[s[i] - 'a'];
    }

    if (a <= s && s <= b) {
        cout << "YES\n";
        for (int x : perm) {
            cout << char('a' + x);
        }
        cout << "\n";
    } else {
        cout << "NO\n";
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt;
    cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}