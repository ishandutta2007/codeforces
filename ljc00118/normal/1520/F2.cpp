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

const int N = 2e5 + 5, B = 32;

int cnt[N];
int n, T;

int query(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int ans; cin >> ans; return r - l + 1 - ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> T;
    int len = (n - 1) / B + 1, k;
    cin >> k;
    for (int i = 1; i <= len; i++) cnt[i] = query((i - 1) * B + 1, min(n, i * B));;
    for (int _ = 1; _ <= T; _++) {
        if (_ != 1) cin >> k;
        for (int i = 1; i <= len; i++) {
            if (cnt[i] >= k) {
                --cnt[i];
                int l = (i - 1) * B + 1, r = min(n, i * B), ans = r, tem = l; --r;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (query(tem, mid) >= k) ans = mid, r = mid - 1;
                    else l = mid + 1;
                }
                cout << "! " << ans << endl;
                break;
            }
            k -= cnt[i];
        }
    }
    return 0;
}