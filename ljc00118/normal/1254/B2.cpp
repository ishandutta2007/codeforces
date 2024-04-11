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

const int N = 1e6 + 5;

int a[N], tmp[N];
int n;
ll ans = -1, sum;

void solve(ll x) {
    memcpy(tmp, a, sizeof(tmp));
    ll sum = 0;
    for(register int l = 1, r; l <= n; l = r + 1) {
        a[l] %= x;
        if(a[l] == 0) { r = l; continue; }
        ll now = a[l];
        int mid = 0;
        if(a[l] >= (x + 1) / 2) sum -= l * (x - a[l]), mid = 1;
        else sum -= 1ll * l * a[l];
        r = l;
        while(now + a[r + 1] < x) {
            ++r, now += a[r];
            if(now - a[r] < (x + 1) / 2 && now >= (x + 1) / 2) {
                sum += (now - a[r]) * r;
                sum -= (x - now) * r;
                mid = 1;
            } else if(!mid) sum -= 1ll * a[r] * r;
            else sum += 1ll * a[r] * r;
        }
        if(now < (x + 1) / 2) {
            sum += now * (r + 1);
        } else {
            sum += 1ll * (x - now) * (r + 1);
        }
        a[r + 1] -= (x - now);
    }
    if(ans == -1) ans = sum;
    else ans = min(ans, sum);
    memcpy(a, tmp, sizeof(a));
}

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) {
        read(a[i]);
        sum += a[i];
    }
    for(register int i = 2; 1ll * i * i <= sum; i++) {
        if(sum % i == 0) {
            solve(i);
            while(sum % i == 0) sum /= i;
        }
    }
    if(sum != 1) solve(sum);
    print(ans, '\n');
    return 0;
}