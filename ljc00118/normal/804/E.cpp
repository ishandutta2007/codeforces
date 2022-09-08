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

int n, opt;

void sol(int a, int b) {
    if(opt && a % 2 == 1 && b % 2 == 0 && a + 1 == b) {
        print(a, ' '); print(n, '\n');
        print(a, ' '); print(b, '\n');
        print(b, ' '); print(n, '\n');
    } else {
        print(a, ' '); print(b, '\n');
    }
}

void solve1(int a) {
    sol(a + 2, a + 3);
    sol(a + 1, a + 3);
    sol(a + 0, a + 2);
    sol(a + 0, a + 3);
    sol(a + 1, a + 2);
    sol(a + 0, a + 1);
}

void solve2(int a, int b) {
    sol(a + 0, b + 0);
    sol(a + 1, b + 1);
    sol(a + 2, b + 2);
    sol(a + 3, b + 3);

    sol(a + 1, b + 0);
    sol(a + 2, b + 1);
    sol(a + 3, b + 2);
    sol(a + 0, b + 3);

    sol(a + 3, b + 0);
    sol(a + 0, b + 1);
    sol(a + 1, b + 2);
    sol(a + 2, b + 3);

    sol(a + 0, b + 2);
    sol(a + 1, b + 3);
    sol(a + 2, b + 0);
    sol(a + 3, b + 1);
}

int main() {
    read(n);
    if(n % 4 == 0 || n % 4 == 1) {
        printf("YES\n");
        opt = n % 4;
        for(register int i = 1; i <= n / 4 * 4; i += 4) {
            solve1(i);
            for(register int j = i + 4; j <= n / 4 * 4; j += 4) {
                solve2(i, j);
            }
        }
    } else {
        printf("NO\n");
    }
    return 0;
}