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

ll st[N][3], cnt, k, b;
int m, top = 1;

ll calc(int pos) { return (k + st[pos][0]) * st[pos][2] + b + st[pos][1]; }

int main() {
    cin >> cnt >> m; --cnt;
    while(m--) {
        int opt; read(opt);
        if(opt == 1) {
            int t; read(t);
            top = 1; k = b = 0;
            st[1][0] = st[1][1] = st[1][2] = 0;
            cnt += t;
        }
        if(opt == 2) {
            int t; read(t);
            if(calc(top) == 0) {
                cnt += t;
            } else {
                while(top > 1 && calc(top) * (st[top][2] - st[top - 1][2]) >= (calc(top - 1) - calc(top)) * (cnt + 1 - st[top][2])) --top;
                ++top; st[top][0] = -k; st[top][1] = -b; st[top][2] = cnt + 1; cnt += t;
            }
        }
        if(opt == 3) {
            int a, b; read(a); read(b);
            k += b; ::b += a;
            while(top > 1 && calc(top - 1) <= calc(top)) --top;
        }
        // fprintf(stderr, "stack : ");
        // for(register int i = 1; i <= top; i++) fprintf(stderr, "%I64d ", st[i][2]);
        // fprintf(stderr, "\n");
        print(st[top][2] + 1, ' '); print(calc(top), '\n');
    }
    return 0;
} //