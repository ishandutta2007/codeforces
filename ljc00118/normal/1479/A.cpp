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

int n;

int query(int pos) {
    cout << "? " << pos << endl;
    int ans; cin >> ans; return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int l = 0, r = n;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        int t1 = query(mid), t2 = query(mid + 1);
        if (t1 > t2) l = mid;
        else r = mid;
    }
    cout << "! " << l + 1 << endl;
    return 0;
}