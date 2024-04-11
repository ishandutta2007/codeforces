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

vector <int> adj[N];
int fa[N], siz[N], val[N], tag[N], cant[N], id[N], l[N], r[N];
char c[N];
int n, m, ans;

pii find(int x) {
    int col = tag[x];
    while (fa[x]) {
        x = fa[x];
        col ^= tag[x];
    }
    return make_pair(x, col);
}

int main() {
    read(n); read(m); scanf("%s", c + 1);
    for (int i = 1; i <= m; i++) {
        int k; read(k);
        for (int j = 1; j <= k; j++) {
            int x; read(x);
            if (!id[x]) id[x] = i;
            else l[x] = id[x], r[x] = i;
        }
    }
    for (int i = 1; i <= m; i++) siz[i] = 1;
    for (int i = 1; i <= n; i++) {
        // fprintf(stderr, "tag[2] = %d, tag[3] = %d\n", tag[2], tag[3]);
        if (!l[i]) {
            if (!id[i]) {
                assert(c[i] - '0');
                print(ans, '\n');
            } else {
                pii x = find(id[i]);
                // fprintf(stderr, "i = %d, x.first = %d, x.second = %d\n", i, x.first, x.second);
                if (x.second ^ (c[i] - '0')) {
                    cant[x.first] = 1;
                    print(ans, '\n');
                } else {
                    tag[x.first] ^= 1;
                    ans += (siz[x.first] - 2 * val[x.first]);
                    val[x.first] = siz[x.first] - val[x.first];
                    cant[x.first] = 1;
                    print(ans, '\n');
                }
            }
            continue;
        }
        pii x = find(l[i]), y = find(r[i]);
        // fprintf(stderr, "i = %d, x.first = %d, x.second = %d, y.first = %d, y.second = %d\n", i, x.first, x.second, y.first, y.second);
        if (x.first == y.first) {
            assert(x.second ^ y.second ^ (c[i] - '0'));
            print(ans, '\n');
            continue;
        }
        if (siz[x.first] > siz[y.first]) swap(x, y);
        if (x.second ^ y.second ^ (c[i] - '0')) {
            fa[x.first] = y.first; siz[y.first] += siz[x.first]; val[y.first] += val[x.first]; cant[y.first] |= cant[x.first]; tag[x.first] ^= tag[y.first];
            print(ans, '\n');
        } else {
            // fprintf(stderr, "i = %d, x.first = %d, y.first = %d, cant[%d] = %d, cant[%d] = %d\n", i, x.first, y.first, x.first, cant[x.first], y.first, cant[y.first]);
            assert(!cant[x.first] || !cant[y.first]);
            if ((siz[x.first] - 2 * val[x.first] < siz[y.first] - 2 * val[y.first] && !cant[x.first]) || cant[y.first]) {
                ans += (siz[x.first] - 2 * val[x.first]);
                val[x.first] = siz[x.first] - val[x.first];
                tag[x.first] ^= 1;
            } else {
                ans += (siz[y.first] - 2 * val[y.first]);
                val[y.first] = siz[y.first] - val[y.first];
                tag[y.first] ^= 1;
            }
            fa[x.first] = y.first; siz[y.first] += siz[x.first]; val[y.first] += val[x.first]; cant[y.first] |= cant[x.first]; tag[x.first] ^= tag[y.first];
            print(ans, '\n');
        }
    }
    return 0;
}