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

const int N = 3e5 + 5;

set <int> res;
set <int> :: iterator it;
int st[N][20], a[N];
int n, ans;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int query(int l, int r) {
    int k = 0;
    while((1 << (k + 1)) <= r - l + 1) ++k;
    return gcd(st[l][k], st[r - (1 << k) + 1][k]);
}

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) read(a[i]), st[i][0] = a[i];
    for(register int j = 1; j <= 19; j++) {
        for(register int i = 1; i <= n - (1 << j) + 1; i++) {
            st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    for(register int i = 1; i <= n; i++) {
        int l = 1, r = i - 1, L = i;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(query(mid, i) == a[i]) r = mid - 1, L = mid;
            else l = mid + 1;
        }
        l = i + 1, r = n; int R = i;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(query(i, mid) == a[i]) l = mid + 1, R = mid;
            else r = mid - 1;
        }
        if(R - L + 1 > ans) {
            ans = R - L + 1;
            res.clear();
            res.insert(L);
        } else if(R - L + 1 == ans) res.insert(L);
    }
    print(res.size(), ' '); print(ans - 1, '\n');
    while(res.size()) {
        it = res.begin();
        print(*it, ' ');
        res.erase(it);
    }
    putchar('\n');
    return 0;
}