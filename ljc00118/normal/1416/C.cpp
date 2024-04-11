#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
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

const int N = 3e5 + 5;

int a[N], id[N], f[N];
int n, mask, ans, len; ll cnt;

bool cmp(int x, int y) {
    if ((a[x] & mask) != (a[y] & mask)) return (a[x] & mask) < (a[y] & mask);
    return x < y;
}

int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]), id[i] = i;
    for (int i = 29; i >= 0; i--) {
        sort(id + 1, id + n + 1, cmp);
        ll sum0 = 0, sum1 = 0;
        for (int l = 1, r; l <= n; l = r + 1) {
            r = l;
            while (r < n && ((a[id[l]] & mask) == (a[id[r + 1]] & mask))) ++r;
            // cout << "?" << l << " " << r << endl;
            int cnt0 = 0, cnt1 = 0;
            for (int j = l; j <= r; j++) {
                if ((a[id[j]] >> i) & 1) {
                    sum1 += cnt0;
                    ++cnt1;
                } else {
                    sum0 += cnt1;
                    ++cnt0;
                }
            }
        }
        // cout << "!" << i << " " << sum0 << " " << sum1 << endl;
        if (sum0 <= sum1) cnt += sum0;
        else ans |= (1 << i), cnt += sum1;
        mask |= (1 << i);
    }
    print(cnt, ' '); print(ans, '\n');
    return 0;
}