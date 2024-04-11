#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

template <typename T>
struct hash_map_t {
    vector <T> v, val, nxt;
    vector <int> head;
    int mod, tot, lastv;
    T lastans;
    bool have_ans;

    hash_map_t (int md = 0) {
        head.clear(); v.clear(); val.clear(); nxt.clear(); tot = 0; mod = md;
        nxt.resize(1); v.resize(1); val.resize(1); head.resize(mod);
        have_ans = 0;
    }

    bool count(int x) {
        int u = x % mod;
        for(register int i = head[u]; i; i = nxt[i]) {
            if(v[i] == x) {
                have_ans = 1;
                lastv = x;
                lastans = val[i];
                return 1;
            }
        }
        return 0;
    }

    void ins(int x, int y) {
        int u = x % mod;
        nxt.push_back(head[u]); head[u] = ++tot;
        v.push_back(x); val.push_back(y);
    }

    int qry(int x) {
        if(have_ans && lastv == x) return lastans;
        count(x);
        return lastans;
    }
};

const int N = 1e5 + 5;

int st[N][20], wz[N][20];
ll f[N], ans;
int a[N];
int n;

int query(int l, int r) {
    int k = 0;
    while((1 << (k + 1)) <= r - l + 1) ++k;
    if(st[l][k] > st[r - (1 << k) + 1][k]) return wz[l][k];
    return wz[r - (1 << k) + 1][k];
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(register int i = 1; i < n; i++) cin >> a[i], st[i][0] = a[i], wz[i][0] = i;
    st[n][0] = wz[n][0] = n;
    for(register int j = 1; j <= 18; j++) {
        for(register int i = 1; i <= n - (1 << j) + 1; i++) {
            if(st[i][j - 1] > st[i + (1 << (j - 1))][j - 1]) st[i][j] = st[i][j - 1], wz[i][j] = wz[i][j - 1];
            else st[i][j] = st[i + (1 << (j - 1))][j - 1], wz[i][j] = wz[i + (1 << (j - 1))][j - 1];
        }
    }
    for(register int i = n - 1; i >= 1; i--) {
        int w = query(i + 1, a[i]);
        f[i] = f[w] + n - i - a[i] + w;
    }
    for(register int i = 1; i <= n; i++) ans += f[i];
    cout << ans << endl;
    return 0;
}