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

int a[N], pre[N], A[N * 5], B[N * 5];
int n, len;

void s(int x, int y) {
    if(x > y) swap(x, y);
    if(y - x >= n / 2) {
        ++len;
        A[len] = x;
        B[len] = y;
        swap(a[x], a[y]);
    } else {
        int L = 1, R = n;
        if(x == 1) L = 2;
        if(y == n) R = n - 1;
        if(x - 1 >= n / 2 && y - 1 >= n / 2) {
            ++len; A[len] = x; B[len] = 1;
            ++len; A[len] = 1; B[len] = y;
            ++len; A[len] = 1; B[len] = x;
            swap(a[x], a[y]);
            swap(pre[a[x]], pre[a[y]]);
            return;
        }
        if(n - x >= n / 2 && n - y >= n / 2) {
            ++len; A[len] = x; B[len] = n;
            ++len; A[len] = n; B[len] = y;
            ++len; A[len] = n; B[len] = x;
            swap(a[x], a[y]);
            swap(pre[a[x]], pre[a[y]]);
            return;
        }
        ++len; A[len] = x; B[len] = R;
        ++len; A[len] = R; B[len] = L;
        ++len; A[len] = L; B[len] = y;
        ++len; A[len] = L; B[len] = R;
        ++len; A[len] = R; B[len] = x;
        swap(a[x], a[R]);
        swap(a[R], a[L]);
        swap(a[L], a[y]);
        swap(a[L], a[R]);
        swap(a[R], a[x]);
    }
    swap(pre[a[x]], pre[a[y]]);
}

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) read(a[i]), pre[a[i]] = i;
    if(n == 2) {
        if(a[1] == 1) {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
            cout << 1 << " " << 2 << endl;
        }
        return 0;
    }
    for(register int i = 1; i <= n; i++) {
        if(a[i] != i) {
            s(i, pre[i]);
        }
    }
    print(len, '\n');
    for(register int i = 1; i <= len; i++) print(A[i], ' '), print(B[i], '\n');
    // for(register int i = 1; i <= n; i++) print(a[i], ' ');
    return 0;
}