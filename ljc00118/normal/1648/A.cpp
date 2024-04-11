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

const int N = 1e5 + 5;

vector <int> vec[N * 2];
int n, m; ll ans;

int main() {
    read(n); read(m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int a; read(a);
            vec[a].push_back(i);
            vec[a + 100000].push_back(j);
        }
    }
    for (int i = 1; i <= 200000; i++) {
        sort(vec[i].begin(), vec[i].end());
        for (int j = 0; j < (int)vec[i].size(); j++) {
            ans += 1ll * vec[i][j] * (j * 2 - (int)vec[i].size() + 1);
        }
    }
    print(ans, '\n');
    return 0;
}