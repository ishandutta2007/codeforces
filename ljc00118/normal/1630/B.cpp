#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
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

const int N = 2e5 + 5;

int a[N], cnt[N];
int T, n, k;

int main() {
    read(T);
    while (T--) {
        read(n); read(k);
        for (int i = 1; i <= n; i++) cnt[i] = 0;
        for (int i = 1; i <= n; i++) read(a[i]), ++cnt[a[i]];
        int l = 1, r = n;
        for (int i = 1, j = 0, sum = 0; i <= n; i++) {
            while (j < n && sum - (n - sum) < k) {
                ++j;
                sum += cnt[j];
            }
            if (sum - (n - sum) >= k && j - i < r - l) {
                l = i; r = j;
            }
            sum -= cnt[i];
        }
        print(l, ' '); print(r, '\n');
        int cnt = 0;
        for (int i = 1, j; i <= n; i = j + 1) {
            ++cnt;
            if (cnt == k) {
                print(i, ' '); print(n, '\n');
                break;
            }
            j = i;
            int sum = (a[i] >= l && a[i] <= r) ? 1 : -1;
            while (sum != 1) {
                ++j;
                sum += (a[j] >= l && a[j] <= r) ? 1 : -1;
            }
            print(i, ' '); print(j, '\n');
        }
    }
    return 0;
}