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

const int N = 3e5 + 5;

struct ele {
    int val, id;
    bool operator < (const ele A) const { return val < A.val; }
} t[N];

int a[N], b[N], id[N], ans[N * 5][3];
ll sum;
int n, len;

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) read(a[i]), sum += a[i];
    for(register int i = 1; i <= n; i++) read(b[i]), sum -= b[i];
    for(register int i = 1; i <= n; i++) t[i].val = a[i], t[i].id = i;
    sort(t + 1, t + n + 1);
    for(register int i = 1; i <= n; i++) a[i] = t[i].val, id[i] = t[i].id;
    sort(b + 1, b + n + 1);
    if(sum != 0) {
        cout << "NO" << endl;
        return 0;
    }
    int now = 2;
    for(register int i = 1; i <= n; i++) {
        if(b[i] < a[i]) {
            cout << "NO" << endl;
            return 0;
        }
        while(b[i] > a[i]) {
            while(b[now] >= a[now]) ++now;
            int det = min(b[i] - a[i], a[now] - b[now]);
            a[i] += det; a[now] -= det;
            ++len; ans[len][0] = id[i]; ans[len][1] = id[now]; ans[len][2] = det;
        }
    }
    cout << "YES" << endl;
    print(len, '\n');
    for(register int i = 1; i <= len; i++) {
        print(ans[i][0], ' ');
        print(ans[i][1], ' ');
        print(ans[i][2], '\n');
    }
    return 0;
}