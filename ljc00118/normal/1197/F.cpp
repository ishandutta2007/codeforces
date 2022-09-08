#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
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

    void clear() { *this = hash_map_t(mod); }

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

const int N = 1005, md = 998244353;

inline int add(int x, int y) {
    x += y;
    if(x >= md) x -= md;
    return x;
}

inline int sub(int x, int y) {
    x -= y;
    if(x < 0) x += md;
    return x;
}

inline int mul(int x, int y) { return 1ll * x * y % md; }

inline int fpow(int x, int y) {
    int ans = 1;
    while(y) {
        if(y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

struct mat { int a[64][64]; } mt[4], pw[30];

mat operator + (const mat a, const mat b) {
    mat ans; memset(ans.a, 0, sizeof(ans.a));
    for(register int i = 0; i < 64; i++) {
        for(register int j = 0; j < 64; j++) {
            ans.a[i][j] = add(a.a[i][j], b.a[i][j]);
        }
    }
    return ans;
}

mat operator * (const mat a, const mat b) {
    mat ans; memset(ans.a, 0, sizeof(ans.a));
    for(register int i = 0; i < 64; i++) {
        for(register int j = 0; j < 64; j++) {
            for(register int k = 0; k < 64; k++) {
                ans.a[i][j] = add(ans.a[i][j], mul(a.a[i][k], b.a[k][j]));
            }
        }
    }
    return ans;
}

mat operator ^ (const mat a, int k) {
    mat ans; memset(ans.a, 0, sizeof(ans.a));
    for(register int i = 0; i < 64; i++) ans.a[i][i] = 1;
    while(k) {
        if(k & 1) ans = ans * a;
        k >>= 1; k = k * k;
    }
    return ans;
}

struct vec { int a[64]; };

vec operator * (const mat a, const vec b) {
    vec ans; memset(ans.a, 0, sizeof(ans.a));
    for(register int i = 0; i < 64; i++) {
        for(register int j = 0; j < 64; j++) {
            ans.a[i] = add(ans.a[i], mul(a.a[i][j], b.a[j]));
        }
    }
    return ans;
}

vector <pii> col[N];
int a[N], b[4][4], res[4], tmp[4], sum[4];
int n, m;

mat solve(int id) {
    mat ans; memset(ans.a, 0, sizeof(ans.a));
    for(register int i = 0; i <= 3; i++) {
        for(register int j = 0; j <= 3; j++) {
            for(register int k = 0; k <= 3; k++) {
                int now = i * 16 + j * 4 + k;
                int cnt[4] = {0, 0, 0, 0};
                if(b[id][1]) ++cnt[k];
                if(b[id][2]) ++cnt[j];
                if(b[id][3]) ++cnt[i];
                int t = 0;
                while(cnt[t]) ++t;
                int go = j * 16 + k * 4 + t;
                ans.a[go][now] = 1;
            }
        }
    }
    return ans;
}

void fpow(vec &x, int k) {
    for(register int i = 0; i <= 29; i++) {
        if((k >> i) & 1) {
            x = pw[i] * x;
        }
    }
}

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) read(a[i]);
    read(m);
    for(register int i = 1; i <= m; i++) {
        int x, y, c;
        read(x); read(y); read(c);
        col[x].push_back(make_pair(y, c));
    }
    for(register int i = 1; i <= 3; i++) {
        for(register int j = 1; j <= 3; j++) {
            read(b[i][j]);
        }
        mt[i] = solve(i);
    }
    pw[0] = mt[1] + mt[2] + mt[3]; res[0] = 1;
    for(register int i = 1; i <= 29; i++) pw[i] = pw[i - 1] * pw[i - 1];
    for(register int i = 1; i <= n; i++) {
        sort(col[i].begin(), col[i].end());
        vec ans; memset(ans.a, 0, sizeof(ans.a));
        ans.a[63] = 1;
        int now = 0;
        for(register int j = 0; j < (int)col[i].size(); j++) {
            fpow(ans, col[i][j].first - now - 1);
            ans = mt[col[i][j].second] * ans;
            now = col[i][j].first;
        }
        fpow(ans, a[i] - now);
        memset(sum, 0, sizeof(sum));
        for(register int j = 0; j < 64; j++) sum[j & 3] = add(sum[j & 3], ans.a[j]);
        memcpy(tmp, res, sizeof(tmp)); memset(res, 0, sizeof(res));
        for(register int j = 0; j < 4; j++) {
            for(register int k = 0; k < 4; k++) {
                res[j ^ k] = add(res[j ^ k], mul(tmp[j], sum[k]));
            }
        }
    }
    print(res[0], '\n');
    return 0;
}