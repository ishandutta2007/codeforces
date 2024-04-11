#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vec vector
#define ar array

#define all(a) (a).begin(), (a).end()
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

const int INF = 1e9;

inline void no() {
    cout << "-1\n";
    exit(0);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vec<int> inv(n);
    vec<int> a(n);
    bool bad = false;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (max(x, y) < n || min(x, y) >= n) {
            bad = true;
        } else {
            inv[min(x, y)] = x > y;
            a[min(x, y)] = max(x, y);
        }
    }
    if (bad) {
        no();
    }
    vec<int> suf_max(n + 1, -INF);
    for (int i = n - 1; i >= 0; i--) {
        suf_max[i] = max(suf_max[i + 1], a[i]);
    }
    int pref_min = INF;
    int ans = 0;
    vec<int> seq1{INF}, seq2{INF};
    int cost1 = 0, cost2 = 0;
    for (int i = 0; i < n; i++) {
        pref_min = min(pref_min, a[i]);
        if (a[i] < seq1.back()) {
            seq1.push_back(a[i]);
            cost1 += inv[i];
        } else if (a[i] < seq2.back()) {
            seq2.push_back(a[i]);
            cost2 += inv[i];
        } else {
            no();
        }
        if (pref_min > suf_max[i + 1]) {
            ans += min(cost1 + len(seq2) - 1 - cost2, len(seq1) - 1 - cost1 + cost2);
            seq1 = seq2 = {INF};
            cost1 = cost2 = 0;
        }
    }
    cout << ans << '\n';
}