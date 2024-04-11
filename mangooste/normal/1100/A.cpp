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



int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vec<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int cnt[2]{};
        for (int j = 0; j < n; j++) {
            cnt[a[j] == 1]++;
        }
        for (int z = -n; z <= n; z++) {
            int j = i + k * z;
            if (j >= 0 && j < n) cnt[a[j] == 1]--;
        }
        mx = max(mx, abs(cnt[0] - cnt[1]));
    }
    cout << mx << '\n';
}