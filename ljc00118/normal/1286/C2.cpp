#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
 
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}
 
template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}
 
template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 105;

queue <int> q;
vector <pii> adj[N];
int ans[N], sum[N];
string str;
int n;

void add(int x, int y, int s) {
    // fprintf(stderr, "x = %d, y = %d, s = %d\n", x, y, s);
    if (x == y) { ans[x] = s; return; }
    adj[x].push_back(make_pair(y, s));
    adj[y].push_back(make_pair(x, s));
}

void solve(int l, int r) {
    cout << "? " << l << " " << r << endl;
    memset(sum, 0, sizeof(sum));
    int n = r - l + 1;
    for (int i = 1; i <= n * (n + 1) / 2; i++) {
        cin >> str; int len = (int)str.size();
        for (int j = 0; j < len; j++) sum[len] += str[j];
    }
    int las = sum[n], cnt = 0;
    while (1) {
        if (r - l + 1 <= 2) {
            add(l, r, sum[n - cnt] - sum[n - cnt + 1]);
            break;
        }
        add(l, r, las - (sum[n - cnt - 1] - sum[n - cnt]));
        las = (sum[n - cnt - 1] - sum[n - cnt]); ++l; --r; ++cnt;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    if (n == 1) {
        solve(1, 1);
        cout << "! " << (char)ans[1] << endl;
        return 0;
    }
    solve(1, n);
    int mid = (n + 1) >> 1;
    if (n & 1) solve(1, mid), solve(mid + 1, n);
    else solve(1, mid), solve(mid, n);
    for (int i = 1; i <= n; i++) if (ans[i]) q.push(i);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < (int)adj[u].size(); i++) {
            int v = adj[u][i].first;
            if (!ans[v]) {
                ans[v] = adj[u][i].second - ans[u];
                q.push(v);
            }
        }
    }
    cout << "! ";
    for (int i = 1; i <= n; i++) cout << (char)ans[i];
    cout << endl;
    return 0;
}