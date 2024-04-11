#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()

inline void setmax(ll &a, ll b) {
    if (a < b)
        a = b;
}

void solve() {
    int n;
    cin >> n;
    vec<int> tag(n);
    for (auto &x : tag)
        cin >> x;
    vec<ll> s(n);
    for (auto &x : s)
        cin >> x;

    vec<ll> suf_max(n + 1);
    vec<ll> mx(n);
    mx[0] = 0;
    for (int i = 1; i < n; i++) {
        fill(all(suf_max), 0);
        for (int j = i - 1; j >= 0; j--) {
            suf_max[j] = suf_max[j + 1];
            if (tag[j] != tag[i])
                setmax(suf_max[j], mx[j] + abs(s[i] - s[j]));
        }
        mx[i] = suf_max[0];
        for (int j = 0; j < i; j++)
            if (tag[j] != tag[i])
                setmax(mx[j], suf_max[j + 1] + abs(s[i] - s[j]));
        for (int j = 0; j < i; j++)
            if (tag[j] != tag[i])
                setmax(mx[j], abs(s[i] - s[j]));
    }
    cout << *max_element(all(mx)) << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}