/*input
3 3 1
1 2 3
4 5 6
7 8 9

4 5 2
0 2 1 1 0
0 0 3 1 2
1 0 4 3 1
3 3 0 0 4

4 5 2
0 2 1 1 0
0 0 3 1 2
1 0 4 3 1
3 3 0 0 4
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x,y) ((x>>y)&1)
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
#define debug(x...) {cout << "[" << #x << "] ="; print(x);}
void print() {cout << endl;}
template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value << ' ', print(values...);}
#endif
const int N = 2e4 + 5;

int n, m, len;
int _a[55][N];
int dp[55][N];

const int INF = numeric_limits<int>::max() / 2;;
class ITrangeMaxMin {
public:
#define mid ((l+r)/2)
    int n, f[4 * N], lazy[4 * N];
    void dolazy(int k, int l, int r) {
        if (lazy[k] == 0) return;
        f[k] += lazy[k];
        if (l != r) {
            lazy[k * 2] += lazy[k];
            lazy[k * 2 + 1] += lazy[k];
        }
        lazy[k] = 0;
    }
    void init(int k, int l, int r, vector<int>&val) {
        f[k] = lazy[k] = 0; if (l == r) {
            f[k] = val[l - 1];
            return;
        }
        init(k * 2, l, mid, val); init(k * 2 + 1, mid + 1, r, val);
        f[k] = max(f[k * 2], f[k * 2 + 1]);
    }
    void update(int k, int l, int r, int L, int R, int val) {
        dolazy(k, l, r);
        if (r < L || R < l) return;
        if (L <= l && r <= R) {
            lazy[k] += val; dolazy(k, l, r);
            return;
        }
        update(k * 2, l, mid, L, R, val); update(k * 2 + 1, mid + 1, r, L, R, val);
        f[k] = max(f[k * 2], f[k * 2 + 1]);
    }
    int get(int k, int l, int r, int L, int R) {
        dolazy(k, l, r);
        if (r < L || R < l) return -INF;
        if (L <= l && r <= R) return f[k];
        return max(get(k * 2, l, mid, L, R), get(k * 2 + 1, mid + 1, r, L, R));
    }
    ITrangeMaxMin() {};
    void init(vector<int> &val) {
        n = val.size();
        init(1, 1, n, val);
    }
    int get(int l, int r) {return get(1, 1, n, l, r);};
    void update(int l, int r, int val) {update(1, 1, n, l, r, val);};
#undef mid
} IT;

ostream &operator<<(ostream &os, ITrangeMaxMin X) {
    loop(i, 1, X.n) os << X.get(i, i) << sp;
    return os;
}
int get1(int x, int l, int r = 0) {
    if (l > r) return 0;
    if (r == 0) r = l + len - 1;
    return _a[x][r] - _a[x][l - 1];
}

int get2(int x, int l, int r = 0) {
    if (l > r) return 0;
    if (r == 0) r = l + len - 1;
    return _a[x][r] - _a[x][l - 1] + _a[x + 1][r] - _a[x + 1][l - 1];
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> len;
    loop(i, 1, n) {
        loop(j, 1, m) cin >> _a[i][j], _a[i][j] += _a[i][j - 1];
    }
    loop(day, 1, n) {
        vector<int> pre; loop(i, 1, m) pre.push_back(dp[day - 1][i]);
        IT.init(pre);
        if (day != 1)
            loop(i, 1, len) IT.update(max(1LL, i - len + 1), i, -get1(day, i, i));
        loop(p, 1, m - len + 1) {
            if (day != 1 && p != 1) {
                int x = p + len - 1;
                IT.update(max(1LL, x - len + 1), x, -get1(day, x, x));
                IT.update(max(1LL, (p - 1) - len + 1), p - 1, get1(day, p - 1, p - 1));
            }
            dp[day][p] = IT.get(1, m) + get2(day, p, p + len - 1);
        }
    }
    int ans = 0;
    loop(p, 1, m) ans = max(ans, dp[n][p]);
    cout << ans << endl;
}