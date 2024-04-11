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
 
const int N = 2e5 + 5;
 
int a[N], id[N], ans[N];
int n;
 
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
 
inline int brand() { return (rand() << 15) ^ rand(); }
 
void solve1() {
    if(clock() > 400) {
        printf("NO\n");
        exit(0);
    }
    for(register int i = 1; i <= n; i++) {
        int x = brand() % n + 1, y = brand() % n + 1;
        swap(a[x], a[y]); swap(id[x], id[y]);
    }
    int d1 = 0, d2 = 0;
    for(register int i = 1; i <= n; i++) {
        int in1 = 0, in2 = 0;
        if(!d1) in1 = 1;
        else if(gcd(d1, a[i]) < d1) in1 = 1;
        if(!d2) in2 = 0;
        else if(gcd(d2, a[i]) < d2) in2 = 1;
        if(in1 + in2 == 2 || in1 + in2 == 0) {
            if(rand() & 1) d1 = gcd(d1, a[i]), ans[id[i]] = 1;
            else d2 = gcd(d2, a[i]), ans[id[i]] = 2;
        } else if(in1) d1 = gcd(d1, a[i]), ans[id[i]] = 1;
        else d2 = gcd(d2, a[i]), ans[id[i]] = 2;
    }
    if(d1 == 1 && d2 == 1) {
        printf("YES\n");
        for(register int i = 1; i <= n; i++) print(ans[i], i == n ? '\n' : ' ');
        exit(0);
    }
}
 
void solve2() {
    if(clock() > 400) {
        printf("NO\n");
        exit(0);
    }
    for(register int i = 1; i <= n; i++) {
        int x = brand() % n + 1, y = brand() % n + 1;
        swap(a[x], a[y]); swap(id[x], id[y]);
    }
    int d1 = 0, d2 = 0;
    for(register int i = 1; i <= n; i++) {
        if(rand() & 1) d1 = gcd(d1, a[i]), ans[id[i]] = 1;
        else d2 = gcd(d2, a[i]), ans[id[i]] = 2;
    }
    if(d1 == 1 && d2 == 1) {
        printf("YES\n");
        for(register int i = 1; i <= n; i++) print(ans[i], i == n ? '\n' : ' ');
        exit(0);
    }
}
 
int main() {
    srand(time(0));
    read(n);
    for(register int i = 1; i <= n; i++) read(a[i]), id[i] = i;
    while(1) { solve1(); solve2(); }
    return 0;
}