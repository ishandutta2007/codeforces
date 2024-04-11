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

const int N = 4e5 + 5, MAXN = 4e5;

int a[N], pri[N], isp[N], n, len, cnt1, cnt2, ans;

void init_pri() {
    for(register int i = 2; i <= MAXN; i++) {
        if(!isp[i]) { pri[++len] = i; }
        for(register int j = 1; j <= len && i * pri[j] <= MAXN; j++) {
            isp[i * pri[j]] = 1;
            if(i % pri[j] == 0) break;
        }
    }
}

int main() {
    init_pri();
    read(n);
    for(register int i = 1; i <= n; i++) {
        read(a[i]);
        if(a[i] == 1) cnt1++;
        else cnt2++;
    }
    if(cnt1) {
        if(cnt2) {
            print(2, ' '); print(1, ' ');
            for(register int i = 1; i < cnt2; i++) print(2, ' ');
            for(register int i = 1; i < cnt1; i++) print(1, ' ');
        } else {
            for(register int i = 1; i <= cnt1; i++) print(1, ' ');
        }
    } else {
        for(register int i = 1; i <= cnt2; i++) print(2, '\n');
    }
    return 0;
}