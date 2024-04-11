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

    int n;
    cin >> n;
    vec<int> a(n);
    vec<int> where(n);
    for (auto &x : a) {
        cin >> x;
        x--;
        if (x != -1) {
            where[x] = -1;
        }
    }
    vec<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i]--;
        if (b[i] != -1) {
            where[b[i]] = i;
        }
    }
    if (where[0] == -1) {
        int ans = 0;
        for (int i = 1; i < n; i++) {
            ans = max(ans, where[i] - (i - 1));
        }
        cout << ans + n << '\n';
        return 0;
    }
    bool ok = true;
    for (int i = 1; i < n - where[0]; i++) {
        ok &= (where[i] == where[i - 1] + 1);
    }
    for (int i = n - where[0]; i < n; i++) {
        ok &= (where[i] <= (i - (n - where[0])) - 1);
    }
    if (ok) {
        cout << where[0] << '\n';
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, where[i] - (i - 1));
    }
    cout << ans + n << '\n';
}