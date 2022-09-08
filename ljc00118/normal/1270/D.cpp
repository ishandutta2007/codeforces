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

int n, k, p1, val1, p2, val2, tmp, cnt;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    if (k == 1) {
        cout << "! 1" << endl;
        return 0;
    }
    cout << "?";
    for (int i = 1; i <= k; i++) cout << " " << i;
    cout << endl;
    cin >> p1 >> val1;
    cout << "?";
    for (int i = 1; i <= k; i++) if (i != p1) cout << " " << i;
    cout << " " << k + 1 << endl;
    cin >> p2 >> val2;
    for (int i = 1; i <= k + 1; i++) {
        if (i == p1 || i == p2) continue;
        cout << "?";
        for (int j = 1; j <= k + 1; j++) if (i != j) cout << " " << j;
        cout << endl;
        cin >> tmp >> tmp;
        if (tmp != val2) ++cnt;
    }
    if (val1 > val2) cout << "! " << cnt + 1 << endl;
    else cout << "! " << k - cnt << endl;
    return 0;
}