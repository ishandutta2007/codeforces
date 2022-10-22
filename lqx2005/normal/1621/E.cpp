#include <bits/stdc++.h>
#define x first
#define y second
#define eb emplace_back
#define sz(a) int((a).size())
#define mid ((l + r) >> 1)
#define ls (p + 1)
#define rs (p + ((mid - l + 1) << 1))
typedef long long ll;
typedef unsigned long long ull;
typedef long double db;
using namespace std;
typedef pair<int, int> pii;
const int N = 1e6 + 10;
struct frac {
    ll x, y;
    frac() {x = y = 0; }
    frac(ll _x, ll _y) {x = _x, y = _y; }
    friend bool operator < (const frac a, const frac b) {
        return a.x * b.y  < b.x * a.y;
    }
    friend bool operator == (const frac a, const frac b) {
        return a.x == b.x && a.y == b.y;
    }
};
struct node {
    int sum, pre;
    node() {sum = pre = 0; }
    node(int _sum, int _pre) {sum = _sum, pre = _pre; }
    friend node operator + (const node a, const node b) {
        return node(a.sum + b.sum, min(b.pre, a.pre + b.sum));
    }
};
int n, m;
node t[N << 1];
int a[N];
ll sum[N];
vector<int> b[N];
frac arr[N];
int atot = 0;
int cnt[N];
void build(int p, int l, int r) {
    t[p] = node(0, 0);
    if(l == r) {
        cnt[l] = 0;
        return;
    }
    build(ls, l, mid), build(rs, mid + 1, r);
    return;
}
void change(int p, int l, int r, int x, int v) {
    if(l == r) {
        cnt[l] += v;
        t[p].sum = cnt[l], t[p].pre = min(0, cnt[l]);
        return;
    }
    if(x <= mid) change(ls, l, mid, x, v);
    else change(rs, mid + 1, r, x, v);
    t[p] = t[ls] + t[rs];
    return;
}
void insert(frac x, int v) {
    int p = lower_bound(arr + 1, arr + atot + 1, x) - arr;
    change(1, 1, atot, p, v);
    // cout << p <<" " << x.x <<" " << x.y <<" " << v << endl;
    return;
}
void solve() {
    atot = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        arr[++atot] = frac(a[i], 1);
    }
    for(int i = 1; i <= m; i++) {
        int k;
        cin >> k;
        b[i].resize(k);
        sum[i] = 0;
        for(int j = 0; j < k; j++) {
            cin >> b[i][j];
            sum[i] += b[i][j];
        }
        arr[++atot] = frac(sum[i], k);
        for(int j = 0; j < k; j++) {
            arr[++atot] = frac(sum[i] - b[i][j], k - 1);
        }
    }
    sort(arr + 1, arr + atot + 1);
    atot = unique(arr + 1, arr + atot + 1) - (arr + 1);
    build(1, 1, atot);
    for(int i = 1; i <= n; i++) insert(frac(a[i], 1), 1);
    for(int i = 1; i <= m; i++) insert(frac(sum[i], sz(b[i])), -1);
    for(int i = 1; i <= m; i++) {
        int k = sz(b[i]);
        insert(frac(sum[i], k), 1);
        for(int j = 0; j < k; j++) {
            insert(frac(sum[i] - b[i][j], k - 1), -1);
            if(t[1].pre < 0) cout << 0;
            else cout << 1;
            insert(frac(sum[i] - b[i][j], k - 1), 1);
        }
        insert(frac(sum[i], k), -1);
    }
    cout << endl;
	return;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t;
	for(cin >> t; t--; solve());
    return 0;
}