#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie();
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
typedef pair <long long, int> pii;
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

const int md = 1e9 + 7;

vector <pii> primes;
int f[10005][65];
ll n; int k, ans = 1;

inline int mul(int x, int y) { return (ll)x * y % md; }

inline int add(int x, int y) {
    x += y;
    if(x >= md) x -= md;
    return x;
}

inline int sub(int x, int y) {
    x -= y;
    if(x < 0) x += md;
    return x;
}

inline int fpow(int x, int y) {
    int ans = 1;
    while(y) {
        if(y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

int main() {
    cin >> n >> k;
    for(register int i = 2; (ll)i * i <= n; i++) {
        if(n % i == 0) {
            int cnt = 0;
            while(n % i == 0) cnt++, n /= i;
            primes.emplace_back(i, cnt);
        }
    }
    if(n > 1) primes.emplace_back(n, 1);
    for(register int i = 0; i < primes.size(); i++) {
        memset(f, 0, sizeof(f)); pii tmp = primes[i];
        f[0][tmp.second] = 1;
        for(register int j = 0; j < k; j++) {
            for(register int t = 0; t <= tmp.second; t++) {
                int cur = mul(f[j][t], fpow(t + 1, md - 2));
                for(register int tt = 0; tt <= t; tt++)
                    f[j + 1][tt] = add(f[j + 1][tt], cur);
            }
        }
        int x = 1, cur = 0;
        for(register int j = 0; j <= tmp.second; j++) {
            cur = add(cur, mul(x, f[k][j]));
            x = mul(x, tmp.first % md);
        }
        ans = mul(ans, cur);
    }
    cout << ans << endl;
    return 0;
} // qwqqaqqwq