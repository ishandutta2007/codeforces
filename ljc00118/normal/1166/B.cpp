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
    int mod, tot, lastv, last_id;
    T lastans;
    bool have_ans;

    hash_map_t (int md = 0) {
        head.clear(); v.clear(); val.clear(); nxt.clear(); tot = 0; mod = md;
        nxt.resize(1); v.resize(1); val.resize(1); head.resize(mod);
        have_ans = 0;
    }

    void clear() {
        for(register int i = 1; i <= tot; i++) head[v[i] % mod] = 0;
        tot = 0;
        v.clear(); val.clear(); nxt.clear();
        v.resize(1); val.resize(1); nxt.resize(1);
        have_ans = 0;
    }

    bool count(int x) {
        int u = x % mod;
        for(register int i = head[u]; i; i = nxt[i]) {
            if(v[i] == x) {
                have_ans = 1;
                lastv = x;
                last_id = i;
                lastans = val[i];
                return 1;
            }
        }
        return 0;
    }

    void ins(int x, int y) {
        // fprintf(stderr, "debug %d %d\n", x, y);
        if(count(x)) {
            val[last_id] = y;
            lastans = y;
            return;
        }
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

const char c[5] = {'a', 'e', 'i', 'o', 'u'};
int n;

int main() {
    cin >> n;
    for(register int i = 5; i <= n; i++) {
        if(n % i == 0 && n / i >= 5) {
            int x = i;
            int y = n / i;
            for(register int _x = 1; _x <= x; _x++) {
                for(register int _y = 1; _y <= y; _y++) {
                    int id = (_x + _y) % 5;
                    putchar(c[id]);
                }
            }
            putchar('\n');
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}