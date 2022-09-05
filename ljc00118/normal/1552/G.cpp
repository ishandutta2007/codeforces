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

const int N = 45;

ll s[N], ss[N], state[N][N], tem[N];
int big[N];
int n, k;

void dfs(int u, ll now) {
    if (u == k + 1) {
        if (now && (now & -now) + now != (1ll << n)) {
            puts("REJECTED");
            exit(0);
        }
        return;
    }
    for (int i = 0; i <= big[u]; i++) {
        int cnt = __builtin_popcountll(now & s[u]) + i;
        dfs(u + 1, (now & ~s[u]) ^ state[u][cnt]);
    }
}

int main() {
    read(n); read(k);
    if (n == 1) {
        puts("ACCEPTED");
        return 0;
    }
    for (int i = 1; i <= k; i++) {
        tem[i] = (1ll << n) - 1;
        vector <int> vec;
        int m; read(m);
        for (int j = 1; j <= m; j++) {
            int x; read(x);
            s[i] |= (1ll << (x - 1));
            tem[x] ^= (1ll << (x - 1));
            vec.push_back(x);
        }
        sort(vec.begin(), vec.end());
        ll now = 0;
        for (int j = 0; j < (int)vec.size(); j++) {
            now |= (1ll << (vec[(int)vec.size() - j - 1] - 1));
            state[i][j + 1] = now;
        }
        ss[i] = ss[i - 1] | s[i];
        big[i] = __builtin_popcountll(ss[i] ^ (ss[i] & ss[i - 1]));
    }
    if (ss[k] != (1ll << n) - 1) {
        puts("REJECTED");
        exit(0);
    }
    dfs(1, 0);
    puts("ACCEPTED");
    return 0;
}