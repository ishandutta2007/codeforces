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

const int N = 8e5 + 5;

multiset <int> L, R;
multiset <int> :: iterator it;
int x[N], y[N], id[N];
int n, len; ll ans;

bool cmp(int i, int j) { return x[i] + y[i] < x[j] + y[j]; }

int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(x[i]), read(y[i]), id[i] = i;
    sort(id + 1, id + n + 1, cmp);
    L.insert(0); R.insert(0);
    for (int i = 1; i <= n; i++) {
        int nowlen = x[id[i]] + y[id[i]] - x[id[i - 1]] - y[id[i - 1]];
        len += nowlen;
        int posl = *L.rbegin(), posr = *R.begin() + len;
        if (x[id[i]] < posl) {
            L.erase(--L.end());
            L.insert(x[id[i]]);
            L.insert(x[id[i]]);
            R.insert(posl - len);
            ans += posl - x[id[i]];
        } else if (x[id[i]] > posr) {
            R.erase(R.begin());
            R.insert(x[id[i]] - len);
            R.insert(x[id[i]] - len);
            L.insert(posr);
            ans += x[id[i]] - posr;
        } else {
            L.insert(x[id[i]]);
            R.insert(x[id[i]] - len);
        }
    }
    print(ans, '\n');
    return 0;
}