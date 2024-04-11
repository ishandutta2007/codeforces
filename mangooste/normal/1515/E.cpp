#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vec vector
#define ar array

#define all(a) begin(a), end(a)
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

const int N = 888;
int dp[N][N], C[N][N], p2[N], n, m;

inline int add(int a, int b) {
    a += b;
    if (a >= m) a -= m;
    return a;
}

inline int mult(int a, int b) {
    return 1ll * a * b % m;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < N; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
        }
    }
    p2[0] = 1;
    for (int i = 1; i < N; i++) {
        p2[i] = add(p2[i - 1], p2[i - 1]);
    }
    for (int i = 1; i < n; i++) {
        dp[i][1] = p2[i - 1];
        for (int cur = 2; cur <= i; cur++) {
            for (int prev = i - 2; prev > 0; prev--) {
                dp[i][cur] = add(dp[i][cur], mult(dp[prev][cur - 1], mult(p2[i - prev - 2], C[(prev + 1 - (cur - 1)) + (i - prev - 1)][i - prev - 1])));
            }
        }
    }
    int ans = p2[n - 1];
    for (int last = 1; last < n - 1; last++) {
        for (int i = 1; i <= last; i++) {
            ans = add(ans, mult(dp[last][i], mult(p2[n - last - 2], C[(last + 1 - i) + (n - last - 1)][n - last - 1])));
        }
    }
    cout << ans << '\n';
}