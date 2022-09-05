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

vector <int> vec[N];
int a[N], f[N], ans[N], ans2[N], r[N];
int T, n, tot;

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

void add(int x, int y) {
    ans[x] = y;
    f[find(x)] = find(y);
}

void add2(int x, int y, int id) {
    if (x == id || y == n - id + 1) swap(x, y);
    add(x, id); add(y, n - id + 1);
}

int main() {
    read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) vec[i].clear();
        for (int i = 1; i <= n; i++) read(a[i]), vec[a[i]].push_back(i);
        int cando = 1, pos = 0;
        for (int i = 1; i <= n; i++) {
            if ((int)vec[i].size() & 1) {
                if (pos) {
                    cando = 0;
                    break;
                }
                pos = i;
            }
        }
        if (!cando) {
            printf("NO\n");
            continue;
        }
        for (int i = 1; i <= n; i++) f[i] = i, r[i] = 0;
        if (pos) {
            int len = (int)vec[pos].size();
            if (len == 1 && vec[pos][0] == n / 2 + 1) {
                printf("NO\n");
                continue;
            }
            if (vec[pos][len - 1] != n / 2 + 1) {
                add(vec[pos][len - 1], n / 2 + 1);
                vec[pos].pop_back();
            } else {
                add(vec[pos][len - 2], n / 2 + 1);
                vec[pos][len - 2] = vec[pos][len - 1];
                vec[pos].pop_back();
            }
        }
        tot = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < (int)vec[i].size(); j += 2) {
                ++tot;
                int x = vec[i][j], y = vec[i][j + 1];
                add2(x, y, tot);
                r[x] = y; r[y] = x;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (!r[i]) continue;
            if (find(i) != find(r[i])) {
                add2(i, r[i], n - ans[i] + 1);
            }
        }
        vector <int> seq;
        for (int i = 1; i <= n; i++) {
            if (find(i) == i) {
                seq.push_back(i);
            }
        }
        for (int i = 0; i < (int)seq.size() - 1; i++) {
            int x = (int)seq[i], y = (int)seq[i + 1];
            int gx = ans[x], gy = ans[y];
            add2(x, r[x], gy); add2(y, r[y], n - gx + 1);
        }
        printf("YES\n");
        for (int i = 1; i <= n; i++) ans2[ans[i]] = i;
        for (int i = 1; i <= n; i++) print(ans2[i], i == n ? '\n' : ' ');
    }
    return 0;
}