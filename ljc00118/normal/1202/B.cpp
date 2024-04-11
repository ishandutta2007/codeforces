#pragma GCC optimize(2)
#pragma GCC optimize(3)
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
 
const int N = 2e6 + 5;
 
char c[N];
int f[105], cnt[15];
int n, las;
 
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
 
int main() {
    scanf("%s", c + 1); n = strlen(c + 1); las = c[1] - '0';
    for(register int i = 2; i <= n; i++) {
        int val = c[i] - '0' - las;
        if(val < 0) val += 10;
        ++cnt[val];
        las = c[i] - '0';
    }
    for(register int i = 0; i <= 9; i++) {
        for(register int j = 0; j <= 9; j++) {
            memset(f, -1, sizeof(f));
            f[0] = 0;
            for(register int k = i; k < 100; k++) {
                if(f[k - i] != -1) {
                    if(f[k] == -1) f[k] = f[k - i] + 1;
                    else f[k] = min(f[k], f[k - i] + 1);
                }
            }
            for(register int k = j; k < 100; k++) {
                if(f[k - j] != -1) {
                    if(f[k] == -1) f[k] = f[k - j] + 1;
                    else f[k] = min(f[k], f[k - j] + 1);
                }
            }
            ll ans = 0;
            bool ok = 1;
            for(register int k = 0; k <= 10; k++) {
                if(k == 0 && (i == 0 || j == 0)) { ans += cnt[0]; continue; }
                if(k == 10 && (i != 0 && j != 0)) cnt[10] = cnt[0];
                int minn = -1;
                for(register int t = 0; t <= 9; t++) {
                    if(k + t * 10 < 100 && f[k + t * 10] != -1) {
                        if(minn == -1) minn = f[k + t * 10];
                        else minn = min(minn, f[k + t * 10]);
                    }
                }
                if(minn == -1 && cnt[k]) {
                    print(-1, ' ');
                    cnt[10] = 0;
                    ok = 0;
                    break;
                } else {
                    ans += 1ll * minn * cnt[k];
                }
                cnt[10] = 0;
            }
            if(ok) print(ans - n + 1, ' ');
        }
        putchar('\n');
    }
    return 0;
}