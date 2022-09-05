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

const int N = 105;

multiset <int> wxw;
int a[N];
int T, n, x;

int main() {
    read(T);
    while (T--) {
        read(n); read(x);
        for (int i = 1; i <= n; i++) read(a[i]);
        int sum = 0, same = 1, cando = 1;
        for (int i = 1; i <= n; i++) {
            sum += a[i];
            if (i > 1 && a[i - 1] != a[i]) same = 0;
            if (sum == x) cando = 0;
        }
        if (sum == x || (same && cando == 0)) {
            printf("NO\n");
        } else {
            printf("YES\n");
            for (int i = 1; i <= n; i++) wxw.insert(a[i]);
            sum = 0;
            for (int i = 1; i <= n; i++) {
                int minn = *wxw.begin();
                int maxn = *(--wxw.end());
                if (sum + minn == x) {
                    sum += maxn;
                    print(maxn, ' ');
                    wxw.erase(wxw.find(maxn));
                } else if (sum + maxn == x) {
                    sum += minn;
                    print(minn, ' ');
                    wxw.erase(wxw.find(minn));
                } else {
                    auto it = wxw.begin(); ++it;
                    if (minn == *it) {
                        sum += minn;
                        print(minn, ' ');
                        wxw.erase(wxw.find(minn));
                    } else {
                        sum += maxn;
                        print(maxn, ' ');
                        wxw.erase(wxw.find(maxn));
                    }
                }
            }
            putchar('\n');
        }
    }
    return 0;
}