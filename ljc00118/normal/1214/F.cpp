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

const ll INF = 0x7fffffffffffffff;
const int N = 2e5 + 5;

// struct Fenwick {
//     ll f[N];
//     int n;

//     inline int lowbit(int x) { return x & -x; }

//     inline void add(int x, int y) {
//         while(x <= n) {
//             f[x] += y;
//             x += lowbit(x);
//         }
//     }

//     inline ll query(int x) {
//         ll ans = 0;
//         while(x) {
//             ans += f[x];
//             x ^= lowbit(x);
//         }
//         return ans;
//     }
// } tr[3];

struct ele {
    int val, id;
    ele (int a = 0, int b = 0) : val(a), id(b) {}
    bool operator < (const ele A) const { return val < A.val; }
} a[N], b[N];

ll s1[N], s2[N];
int ans1[N], ans2[N];
int n, m, pos1, pos2;
ll Ans1 = INF, Ans2 = INF;

int main() {
    read(m); read(n);
    for(register int i = 1; i <= n; i++) read(b[i].val), b[i].id = i;
    for(register int i = 1; i <= n; i++) read(a[i].val), a[i].id = i;
    sort(a + 1, a + n + 1); sort(b + 1, b + n + 1);
    for(register int i = 1; i <= n; i++) {
        if(a[i].val <= b[i].val) {
            s1[0] -= a[i].val;
            s1[n - i + 1] += a[i].val;
        } else if(a[i].val > b[n].val) {
            s1[0] += a[i].val;
            s1[n - i + 1] -= a[i].val;
        } else {
            int pos = lower_bound(b + 1, b + n + 1, ele(a[i].val)) - b - 1;
            s1[0] += a[i].val;
            s1[pos - i + 1] -= a[i].val;
            s1[pos - i + 1] -= a[i].val;
            s1[n - i + 1] += a[i].val;
        }
        s1[n - i + 1] -= a[i].val; s1[n - i + 1] += m;
        // for(register int j = 0; j < n; j++) cout << s1[j] << " ";
        // cout << endl;
    }
    for(register int i = 1; i <= n; i++) {
        if(b[i].val >= a[i].val) {
            s1[0] += b[i].val;
            s1[i] -= b[i].val;
        } else if(b[i].val < a[1].val) {
            s1[0] -= b[i].val;
            s1[i] += b[i].val;
        } else {
            int pos = upper_bound(a + 1, a + n + 1, ele(b[i].val)) - a;
            s1[0] -= b[i].val;
            s1[i - pos + 1] += b[i].val;
            s1[i - pos + 1] += b[i].val;
            s1[i] -= b[i].val;
        }
        s1[i] += b[i].val;
    }
    for(register int i = 0; i <= n; i++) {
        if(i) s1[i] += s1[i - 1];
        if(s1[i] < Ans1) Ans1 = s1[i], pos1 = i;
        // cout << s1[i] << " ";
    }
    // cout << endl;
    for(register int i = 1; i <= n; i++) {
        if(a[i].val >= b[i].val) {
            s2[0] += a[i].val;
            s2[i] -= a[i].val;
        } else if(a[i].val < b[1].val) {
            s2[0] -= a[i].val;
            s2[i] += a[i].val;
        } else {
            int pos = upper_bound(b + 1, b + n + 1, ele(a[i].val)) - b;
            s2[0] -= a[i].val;
            s2[i - pos + 1] += a[i].val;
            s2[i - pos + 1] += a[i].val;
            s2[i] -= a[i].val;
        }
        s2[i] += a[i].val; s2[i] += m;
    }
    for(register int i = 1; i <= n; i++) {
        if(b[i].val <= a[i].val) {
            s2[0] -= b[i].val;
            s2[n - i + 1] += b[i].val;
        } else if(b[i].val > a[n].val) {
            s2[0] += b[i].val;
            s2[n - i + 1] -= b[i].val;
        } else {
            int pos = lower_bound(a + 1, a + n + 1, ele(b[i].val)) - a - 1;
            s2[0] += b[i].val;
            s2[pos - i + 1] -= b[i].val;
            s2[pos - i + 1] -= b[i].val;
            s2[n - i + 1] += b[i].val;
        }
        s2[n - i + 1] -= b[i].val;
    }
    for(register int i = 0; i <= n; i++) {
        if(i) s2[i] += s2[i - 1];
        if(s2[i] < Ans2) Ans2 = s2[i], pos2 = i;
    }
    for(register int i = 1; i <= n; i++) {
        int go = (i + pos1 - 1) % n + 1;
        ans1[b[go].id] = a[i].id;
    }
    for(register int i = 1; i <= n; i++) {
        int go = (i - pos2 + n - 1) % n + 1;
        ans2[b[go].id] = a[i].id;
    }
    // cout << "debug : " << Ans1 << " " << Ans2 << endl;
    if(Ans1 < Ans2) {
        print(Ans1, '\n');
        for(register int i = 1; i <= n; i++) print(ans1[i], i == n ? '\n' : ' ');
    } else {
        print(Ans2, '\n');
        for(register int i = 1; i <= n; i++) print(ans2[i], i == n ? '\n' : ' ');
    }
    return 0;
}