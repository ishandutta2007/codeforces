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
 
const int N = 1e5 + 5;
 
char c[N];
int a[N], b[N], alen, blen;
int n, k, l, r, L, R;
 
int main() {
    read(n); read(k); scanf("%s", c + 1);
    for(register int i = 1; i <= n; i++) {
        if(c[i] == '0' && !l) l = i;
        if(c[i] == '0') a[++alen] = i;
        if(c[i] == '1' && !L) L = i;
        if(c[i] == '1') b[++blen] = i;
    }
    for(register int i = n; i >= 1; i--) {
        if(c[i] == '0' && !r) r = i;
        if(c[i] == '1' && !R) R = i;
    }
    if(!l && !L) { printf("tokitsukaze\n"); return 0; }
    if(R - L + 1 <= k || r - l + 1 <= k) { printf("tokitsukaze\n"); return 0; }
    for(register int i = 1; i <= n - k + 1; i++) {
        int newl = L, newr = R;
        if(i <= newl && newl <= i + k - 1) {
            int l = 1, r = blen;
            while(l <= r) {
                int mid = (l + r) >> 1;
                if(b[mid] > i + k - 1) newl = b[mid], r = mid - 1;
                else l = mid + 1;
            }
        }
        if(i <= newr && newr <= i + k - 1) {
            int l = 1, r = blen;
            while(l <= r) {
                int mid = (l + r) >> 1;
                if(b[mid] < i) newr = b[mid], l = mid + 1;
                else r = mid - 1;
            }
        }
        if(newr - newl + 1 > k) { printf("once again\n"); return 0; } 
    }
    for(register int i = 1; i <= n - k + 1; i++) {
        int newl = l, newr = r;
        if(i <= newl && newl <= i + k - 1) {
            int l = 1, r = alen;
            while(l <= r) {
                int mid = (l + r) >> 1;
                if(a[mid] > i + k - 1) newl = a[mid], r = mid - 1;
                else l = mid + 1;
            }
        }
        if(i <= newr && newr <= i + k - 1) {
            int l = 1, r = alen;
            while(l <= r) {
                int mid = (l + r) >> 1;
                if(a[mid] < i) newr = a[mid], l = mid + 1;
                else r = mid - 1;
            }
        }
        if(newr - newl + 1 > k) { printf("once again\n"); return 0; } 
    }
    printf("quailty\n");
    return 0;
}