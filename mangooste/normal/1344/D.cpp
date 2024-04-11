#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

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

    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    auto find_count = [](int a, ll value) {
        int l = 0, r = a;
        while (r - l > 1) {
            int mid = (l + r) >> 1;
            (a - 3 * (1ll * mid * mid + mid) >= value ? l : r) = mid;
        }
        return r;
    };

    const ll INF = 4e18;
    ll l = -INF, r = INF;
    while (r - l > 1) {
        ll mid = (l + r) >> 1;
        ll cnt = 0;
        for (int i = 0; i < n; i++)
            cnt += find_count(a[i], mid);

        (cnt < k ? r : l) = mid;
    }

    vector<int> answer(n);
    for (int i = 0; i < n; i++) {
        answer[i] = find_count(a[i], r);
        k -= answer[i];
    }
    assert(k >= 0);

    for (int i = 0; i < n; i++) {
        int delta = min<ll>(find_count(a[i], l) - answer[i], k);
        answer[i] += delta;
        k -= delta;
    }

    for (auto x : answer)
        cout << x << ' ';

    cout << '\n';
}