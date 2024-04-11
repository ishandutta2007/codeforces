#include <bits/stdc++.h>
#define int long long
#define Fast_cin ios::sync_with_stdio(false), cin.tie();
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
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

const int N = 5e5 + 5;

ll a[N], fir[N], sec[N];
ll n, l, r, now, cnt, sum;
priority_queue <int> Q;
bool flag = 1;

bool cmp(ll x, ll y) { return x > y; }

inline ll max(ll x, ll y) { return x > y ? x : y; }

void solve(ll &res) {
    sort(a + 1, a + n + 1, cmp);
    
    for(register int i = 1; i <= n; i++) fir[i] = fir[i - 1] + a[i];
    
    while(!Q.empty()) Q.pop(); now = cnt = 0;
    for(register int i = n; i >= 1; i--) {
        Q.push(a[i]); now += a[i]; ll t = now;
        while(!Q.empty() && Q.top() >= i - 1) { now -= Q.top(); t -= Q.top(); cnt++; Q.pop(); }
        sec[i] = t + cnt * (i - 1);
    }
    for(register int i = 1; i <= n; i++) { ll t = fir[i] - sec[i + 1]; res = max(res, t - (ll)i * (i - 1)); }
}

#undef int
int main() {
#define int long long
	read(n);
    for(register int i = 1; i <= n; i++) read(a[i]), sum += a[i];
    solve(l); for(register int i = 1; i <= n; i++) a[i] = n - a[i]; solve(r); r = n - r;
    for(register int i = sum % 2; i <= n; i += 2) if(l <= i && i <= r) flag = 0, print(i, ' ');
    if(flag) print(-1, '\n');
    return 0;
}