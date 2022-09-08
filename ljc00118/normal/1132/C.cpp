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

const int N = 5005;

int L[N], R[N];
int s[N], s1[N], s2[N];
int n, q, ans = 0, now;

int main() {
    read(n); read(q);
    for(register int i = 1; i <= q; i++) {
        int l, r; read(l); read(r);
        ++s[l]; --s[r + 1];
        L[i] = l; R[i] = r;
    }
    for(register int i = 1; i <= n; i++) s[i] += s[i - 1];
    for(register int i = 1; i <= n; i++) {
        s1[i] = s1[i - 1] + (s[i] <= 1);
        s2[i] = s2[i - 1] + (s[i] <= 2);
        now += (s[i] > 0);
    }
    for(register int i = 1; i <= q; i++) {
        for(register int j = i + 1; j <= q; j++) {
            int l1 = L[i], r1 = R[i];
            int l2 = L[j], r2 = R[j];
            if(l1 > l2) swap(l1, l2), swap(r1, r2);
            if(r1 > r2) swap(r1, r2);
            if(r1 < l2) {
                ans = max(ans, now - (s1[r1] - s1[l1 - 1]) - (s1[r2] - s1[l2 - 1]));
            } else {
                ans = max(ans, now - (s1[l2 - 1] - s1[l1 - 1]) - (s2[r1] - s2[l2 - 1]) - (s1[r2] - s1[r1 - 1]));
            }
        }
    }
    cout << ans << endl;
    return 0;
}