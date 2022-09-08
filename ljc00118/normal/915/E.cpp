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

struct node_t {
    int l, r, val;

    node_t (int a = 0, int b = 0, int v = 0) {
        l = a; r = b; val = v;
    }

    bool operator < (const node_t A) const { return l < A.l; }
};

set <node_t> rt;
typedef set <node_t> :: iterator IT;
int n, m, sum;

IT split(int pos) {
    IT it = rt.lower_bound(node_t(pos));
    if(it != rt.end() && it -> l == pos) return it;
    --it; int l = it -> l, r = it -> r, val = it -> val;
    rt.erase(it); rt.insert(node_t(l, pos - 1, val));
    return rt.insert(node_t(pos, r, val)).first;
}

void assign(int l, int r, int val) {
    split(r + 1); IT itl = split(l), itr = split(r + 1);
    for(IT it = itl; it != itr; ++it) if(it -> val) sum -= (it -> r - it -> l + 1);
    rt.erase(itl, itr); rt.insert(node_t(l, r, val));
    if(val) sum += (r - l + 1);
}

int main() {
    read(n); read(m); sum = n;
    rt.insert(node_t(1, n, 1)); rt.insert(node_t(n + 1, n + 1, 0));
    while(m--) {
        int l, r, opt;
        read(l); read(r); read(opt);
        assign(l, r, opt - 1);
        print(sum, '\n');
    }
    return 0;
}