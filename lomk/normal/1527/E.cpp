/*input
7 4
5 5 5 5 2 3 3
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x, y) ((x >> y) & 1)
#define loop(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define rloop(i, l, r) for (int i = (int)l; i >= (int)r; --i)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() {cout << endl;} template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value << ' ', print(values...);}
#endif
const int N = 35005;
const int INF = numeric_limits<int>::max() / 2;

int n, m;
int a[N];
deque<int> dq[N];
int dp[105][N];

int cal(const deque<int> &idq) {
    if (idq.empty()) return 0;
    return idq.back() - idq.front();
}

int query(int l, int r) {
    static int L = 1, R = 0, value = 0;
    while (R < r) {
        int val = a[R + 1];
        value -= cal(dq[val]);
        R++;
        dq[val].push_back(R);
        value += cal(dq[val]);
    }
    while (L > l) {
        int val = a[L - 1];
        value -= cal(dq[val]);
        L--;
        dq[val].push_front(L);
        value += cal(dq[val]);
    }
    while (R > r) {
        int val = a[R];
        value -= cal(dq[val]);
        dq[val].pop_back();
        R--;
        value += cal(dq[val]);
    }
    while (L < l) {
        int val = a[L];
        value -= cal(dq[val]);
        dq[val].pop_front();
        L++;
        value += cal(dq[val]);
    }
    // print(L, R, value);
    return value;
}

void solve(int lev, int l, int r, int L, int R) {
    if (l > r) return;
    int mid = (l + r) / 2; int bpos = -1;
    loop(i, L, min(R, mid - 1)) {
        auto rec = dp[lev - 1][i] + query(i + 1, mid);
        // print(lev, mid, dp[lev - 1][i], query(i + 1, mid));
        if (dp[lev][mid] > rec) {
            dp[lev][mid] = rec;
            bpos = i;
        }
    }
    // print(lev, mid, dp[lev][mid]);
    solve(lev, l, mid - 1, L, bpos);
    solve(lev, mid + 1, r, bpos, R);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    loop(i, 1, n) {
        cin >> a[i];
    }
    memset(dp, 60, sizeof(dp));
    dp[1][0] = INF;
    loop(i, 1, n) dp[1][i] = query(1, i);
    loop(i, 2, m) {
        solve(i, 1, n, 1, n);
    }
    cout << dp[m][n] << endl;
}