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

template<typename T>
inline bool setmin(T &a, const T b) { if (a > b) { a = b; return true; } return false; }

template<typename T>
inline bool setmax(T &a, const T b) { if (a < b) { a = b; return true; } return false; }


const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vec<int> a(n);
    for (auto &x : a)
        cin >> x;

    a.insert(a.begin(), 0);
    a.push_back(0);
    n += 2;

    int k = (n + 1) / 2;
    vec<vec<ll>> dp1(n, vec<ll>(k, INF));
    vec<vec<ll>> dp2(n, vec<ll>(k, INF));

    for (int i = 0; i < n; i++) {
        dp1[i][0] = 0;
        if (i == 0)
            dp2[i][0] = 0;
        else
            dp2[i][0] = max(0, a[i] - a[i - 1] + 1);
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < k; j++)
            setmin(dp1[i][j], min(dp1[i - 1][j], dp2[i - 1][j]));

        if (i == 1)
            continue;

        int value = max(0, a[i] - a[i - 1] + 1);
        for (int j = 1; j < k; j++) {
            setmin(dp2[i][j], dp1[i - 2][j - 1] + value + max(0, a[i - 2] - a[i - 1] + 1));
            if (i != 2)
                setmin(dp2[i][j], dp2[i - 2][j - 1] + value + max(0, min(a[i - 3] - 1, a[i - 2]) - a[i - 1] + 1));
        }
    }

    for (int i = 1; i < k; i++)
        cout << min(dp1.back()[i], dp2.back()[i]) << ' ';

    cout << '\n';
}