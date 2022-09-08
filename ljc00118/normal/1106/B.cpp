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

const int N = 1e5 + 5;

set <pii> wxw;
set <pii> :: iterator it;
int r[N], val[N];
int n, m; ll sum;

ll calc(int x) {
    ll res = 0;
    while(x) {
        it = wxw.begin();
        if(r[it -> second] <= x) res += (ll)it -> first * r[it -> second], x -= r[it -> second], r[it -> second] = 0, wxw.erase(it);
        else {
            res += (ll)it -> first * x;
            r[it -> second] -= x;
            x = 0;
        }
    }
    return res;
}

int main() {
    read(n); read(m);
    for(register int i = 1; i <= n; i++) read(r[i]), sum += r[i];
    for(register int i = 1; i <= n; i++) read(val[i]), wxw.insert(make_pair(val[i], i));
    for(register int i = 1; i <= m; i++) {
        int t, d; read(t); read(d);
        if(d > sum) { sum = 0; print(0, '\n'); continue; }
        ll ans = 0; sum -= d;
        if(r[t] > d) r[t] -= d, ans += (ll)d * val[t];
        else {
            ans += (ll)r[t] * val[t];
            d -= r[t]; r[t] = 0; wxw.erase(make_pair(val[t], t));
            ans += calc(d);
        }
        print(ans, '\n');
    }
    return 0;
}