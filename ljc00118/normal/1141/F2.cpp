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

const int N = 1505;

map <int, int> pre;
map <int, int> :: iterator it;
vector <pii> v[N * N], res;
int f[N * N], dp[N * N], s[N], a[N];
int n, tot, ans;

bool cmp(pii a, pii b) { return a.second < b.second; }

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) read(a[i]), s[i] = s[i - 1] + a[i];
    for(register int l = 1; l <= n; l++) {
        for(register int r = l; r <= n; r++) {
            int val = s[r] - s[l - 1];
            if(pre.count(val)) val = pre[val];
            else pre[val] = ++tot, val = tot;
            v[val].push_back(make_pair(l, r));
        }
    }
    for(register int i = 1; i <= tot; i++) {
        int len = (int)v[i].size();
        sort(v[i].begin(), v[i].end(), cmp);
        f[0] = 1; dp[0] = 0;
        for(register int j = 1; j < len; j++) {
            f[j] = f[j - 1]; dp[j] = -1;
            int l = 0, r = j - 1, ans = -1;
            while(l <= r) {
                int mid = (l + r) >> 1;
                if(v[i][mid].second < v[i][j].first) ans = mid, l = mid + 1;
                else r = mid - 1;
            }
            if(~ans) {
                if(f[ans] + 1 > f[j]) {
                    f[j] = f[ans] + 1;
                    dp[j] = ans;
                }
            }
        }
        if(f[len - 1] > ans) {
            ans = f[len - 1];
            res.clear();
            int now = len - 1;
            while(now >= 0) {
                if(dp[now] == -1) {
                    --now;
                } else {
                    if(!now) {
                        res.push_back(v[i][now]);
                        now = dp[now];
                        break;
                    } else {
                        res.push_back(v[i][now]);
                        now = dp[now];
                    }
                }
            }
            reverse(res.begin(), res.end());
        }
    }
    cout << ans << endl;
    for(register int i = 0; i < ans; i++) {
        print(res[i].first, ' ');
        print(res[i].second, '\n');
    }
    return 0;
}