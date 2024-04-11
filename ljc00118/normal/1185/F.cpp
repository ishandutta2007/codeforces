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

const int N = 1 << 9 | 233;

vector <pii> t[N];
int a[N], cnt[N];
int n, m, Max = -1, ans, ans1, ans2;

int main() {
    read(n); read(m);
    for(register int i = 1; i <= n; i++) {
        int k, now = 0; read(k);
        for(register int j = 1; j <= k; j++) {
            int t; read(t);
            now ^= (1 << (t - 1));
        }
        ++a[now];
    }
    for(register int i = 0; i < (1 << 9); i++) {
        for(register int j = 0; j < (1 << 9); j++) {
            if((i & j) == i) cnt[j] += a[i];
        }
    }
    for(register int i = 1; i <= m; i++) {
        int val, k, now = 0; read(val); read(k);
        for(register int j = 1; j <= k; j++) {
            int t; read(t);
            now ^= (1 << (t - 1));
        }
        t[now].push_back(make_pair(val, i));
    }
    for(register int i = 0; i < (1 << 9); i++) sort(t[i].begin(), t[i].end());
    for(register int i = 0; i < (1 << 9); i++) {
        int maxn = min(1, (int)t[i].size() - 1);
        for(register int j = 0; j <= maxn; j++) {
            for(register int k = 0; k < (1 << 9); k++) {
                int Maxn = min(1, (int)t[k].size() - 1);
                for(register int t = 0; t <= Maxn; t++) {
                    if((i == k) && (j == t)) continue;
                    if(cnt[i | k] > Max) {
                        Max = cnt[i | k];
                        ans = ::t[i][j].first + ::t[k][t].first;
                        ans1 = ::t[i][j].second;
                        ans2 = ::t[k][t].second;
                    } else if(cnt[i | k] == Max && ::t[i][j].first + ::t[k][t].first < ans) {
                        ans = ::t[i][j].first + ::t[k][t].first;
                        ans1 = ::t[i][j].second;
                        ans2 = ::t[k][t].second;
                    }
                }
            }
        }
    }
    print(ans1, ' '); print(ans2, '\n');
    return 0;
}