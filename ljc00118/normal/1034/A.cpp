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

const int N = 3e5 + 5, M = 1.5 * 1e7 + 5;

int cnt[M]; bool used[M];
int a[N];
bool qwq = 1;
int n, d, ans;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
    read(n); ans = n;
    for(register int i = 1; i <= n; i++) read(a[i]);
    for(register int i = 2; i <= n; i++) {
        if(a[i] != a[1]) {
            qwq = 0;
            break;
        }
    }
    if(qwq) {
        cout << -1 << endl;
        return 0;
    }
    for(register int i = 1; i <= n; i++) d = gcd(d, a[i]);
    for(register int i = 1; i <= n; i++) a[i] /= d, ++cnt[a[i]];
    for(register int i = 2; i <= M - 5; i++) {
        if(!used[i]) {
            int sum = 0;
            for(register int j = i; j <= M - 5; j += i) {
                used[j] = 1;
                sum += cnt[j];
            }
            ans = min(ans, n - sum);
        }
    }
    cout << ans << endl;
    return 0;
} //