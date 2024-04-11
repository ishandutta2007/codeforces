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



int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    string s, t;
    int n;
    ll k;
    cin >> n >> k >> s >> t;
    if (k == 1) {
        cout << n << '\n';
        return 0;
    }
    int beg = 0;
    while (beg < n && s[beg] == t[beg]) {
        beg++;
    }
    vec<ll> cnt(n);
    for (int i = beg + 1; i < n; i++) {
        if (s[i] == 'a') {
            cnt[(n - beg) - (i - beg)]++;
        }
        if (t[i] == 'b') {
            cnt[(n - beg) - (i - beg)]++;
        }
    }
    ll ans = beg;
    ans += 2 * (n - beg);
    k -= 2;
    ll to_add = 0;
    for (int i = n - 1; i >= 0; i--) {
        ll cur = cnt[i] + to_add;
        ll num = min(k, cur);
        ans += i * num;
        k -= num;
        to_add += num;
    }
    cout << ans << '\n';
}