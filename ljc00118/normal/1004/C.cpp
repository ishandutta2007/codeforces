#include <bits/stdc++.h>
#define CIOS ios::sync_with_stdio(false);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> ";
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') fu = -1; c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 1e5 + 5;

int s[N], s2[N], used[N], a[N], cnt[N];
int n; ll ans;

int main() {
    read(n);
    for(register int i = 1; i <= n; i++) read(a[i]), cnt[a[i]]++;
    for(register int i = 1; i <= n; i++) {
        s[i] = s[i - 1];
        if(!used[a[i]]) {
            used[a[i]] = 1;
            s[i] += 1;
        }
    }
    memset(used, 0, sizeof(used));
    for(register int i = n; i >= 1; i--) {
        s2[i] = s2[i + 1];
        if(!used[a[i]]) {
            used[a[i]] = 1;
            s2[i] += 1;
        }
    }
    memset(used, 0, sizeof(used)); 
    for(register int i = 1; i < n; i++) {
        if(!used[a[i]]) {
            used[a[i]] = 1;
            ans += s2[i + 1];
//			if(cnt[a[i]] >= 2) ans -= cnt[a[i]];
        }
    }
    cout << ans << endl;
    return 0;
}