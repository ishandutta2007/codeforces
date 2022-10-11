#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define vec vector
#define ar array

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

void solve() {
    int k;
    cin >> k;
    string s, a, b;
    cin >> s >> a >> b;
    int n = len(s);
    for (int rep = 0; rep < 2; rep++) {
        vec<int> to(k, -1);
        vec<int> from(k, -1);
        bool less = false;
        auto finish = [&]() {
            for (int i = 0, j = 0; i < k; i++) {
                if (to[i] != -1) continue;
                while (from[j] != -1) {
                    j++;
                }
                to[i] = j;
                from[j] = i;
            }
            cout << "YES\n";
            if (rep) {
                for (int i = k - 1; i >= 0; i--) {
                    cout << char('a' + k - 1 - to[i]);
                }
            } else {
                for (int i = 0; i < k; i++) {
                    cout << char('a' + to[i]);
                }
            }
            cout << '\n';
        };
        for (int lcp = 0; lcp < n; lcp++) {
            if (to[s[lcp] - 'a'] != -1) {
                int c = to[s[lcp] - 'a'];
                if (less) {
                    if (c > a[lcp] - 'a') {
                        finish();
                        return;
                    }
                } else {
                    if (c < a[lcp] - 'a') break;
                    if (c > a[lcp] - 'a') {
                        bool breaked = false;
                        for (int j = lcp; j < n; j++) {
                            c = to[s[j] - 'a'];
                            if (c != -1) {
                                if (c > b[j] - 'a') {
                                    breaked = true;
                                    break;
                                }
                                if (c == b[j] - 'a') continue;
                                finish();
                                return;
                            } else {
                                int any = 0;
                                while (any < k && from[any] != -1) {
                                    any++;
                                }
                                if (any > b[j] - 'a') {
                                    breaked = true;
                                    break;
                                }
                                to[s[j] - 'a'] = any;
                                from[any] = s[j] - 'a';
                                if (any < b[j] - 'a') {
                                    finish();
                                    return;
                                }
                            }
                        }
                        if (!breaked) {
                            finish();
                            return;
                        }
                        break;
                    }
                }
            } else {
                int any = a[lcp] - 'a' + 1;
                while (any < k && from[any] != -1) {
                    any++;
                }
                if (less) {
                    if (any != k) {
                        to[s[lcp] - 'a'] = any;
                        from[any] = s[lcp] - 'a';
                        finish();
                        return;
                    }
                } else {
                    if (any < b[lcp] - 'a') {
                        to[s[lcp] - 'a'] = any;
                        from[any] = s[lcp] - 'a';
                        finish();
                        return;
                    }
                }
            }
            less |= a[lcp] < b[lcp];
            if (to[s[lcp] - 'a'] != -1) {
                int c = to[s[lcp] - 'a'];
                if (c != a[lcp] - 'a') break;
            } else {
                if (from[a[lcp] - 'a'] != -1) break;
                to[s[lcp] - 'a'] = a[lcp] - 'a';
                from[a[lcp] - 'a'] = s[lcp] - 'a';
            }
            if (lcp == n - 1) {
                finish();
                return;
            }
        }
        auto change = [&](char c) {
            return char(k - 1 - (c - 'a') + 'a');
        };
        for (int i = 0; i < n; i++) {
            s[i] = change(s[i]);
            a[i] = change(a[i]);
            b[i] = change(b[i]);
        }
        swap(a, b);
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}