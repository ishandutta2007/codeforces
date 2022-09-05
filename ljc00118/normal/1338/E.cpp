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

const int N = 8005;

int deg[N], id[N], ban[N], id1[N], id2[N], l[N], r[N], s[N];
bool a[N][N];
char c[N];
int n, x, len1, len2; ll ans;

bool cmp(int i, int j) {
    return deg[i] > deg[j];
}

void solve() {
    for (int i = 1; i <= len1; i++) {
        l[i] = r[i] = 0;
        for (int j = 1; j <= len2; j++) {
            if (a[id1[i]][id2[j]]) {
                if (!l[i]) l[i] = j;
                r[i] = j;
            }
        }
    }
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            s[j] = s[j - 1] + a[id2[j]][id1[i]];
        }
        for (int j = 1; j <= len1; j++) {
            if (j == i) continue;
            ++ans;
            if (j > i) {
                ++ans;
                if (!l[j] || s[r[j]] == s[l[j] - 1]) ++ans;
            }
        }
    }
    memset(s, 0, sizeof(s));
    for (int i = len2; i >= 1; i--) {
        int flag = 0;
        for (int j = 1; j <= len1; j++) {
            if (a[id2[i]][id1[j]]) ++ans;
            else if (s[j] || flag) ans += 2;
            else ans += 3;
            flag |= a[id2[i]][id1[j]];
            s[j] |= a[id2[i]][id1[j]];
        }
    }
}

int main() {
    read(n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", c + 1);
        for (int j = 1; j <= n / 4; j++) {
            int x = (c[j] >= '0' && c[j] <= '9' ? c[j] - '0' : c[j] - 'A' + 10);
            for (int k = 0; k < 4; k++) {
                if ((x >> (3 - k)) & 1) {
                    a[i][(j - 1) * 4 + k + 1] = 1;
                    ++deg[i];
                }
            }
        }
        id[i] = i;
    }
    sort(id + 1, id + n + 1, cmp);
    int now = 1;
    while (now <= n && deg[id[now]] == n - now) {
        ban[id[now]] = 1;
        ans += 614ll * n * (n - now);
        ans += (n - now);
        ++now;
    }
    if (now >= n) {
        print(ans, '\n');
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (!ban[i]) {
            x = i;
            break;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ban[i]) continue;
        if (a[x][i]) {
            id1[++len1] = i;
        }
        if (a[i][x]) {
            id2[++len2] = i;
        }
    }
    id1[++len1] = x;
    memset(deg, 0, sizeof(deg));
    for (int i = 1; i <= len1; i++) {
        for (int j = i + 1; j <= len1; j++) {
            if (a[id1[i]][id1[j]]) {
                ++deg[id1[i]];
            } else {
                ++deg[id1[j]];
            }
        }
    }
    for (int i = 1; i <= len2; i++) {
        for (int j = i + 1; j <= len2; j++) {
            if (a[id2[i]][id2[j]]) {
                ++deg[id2[i]];
            } else {
                ++deg[id2[j]];
            }
        }
    }
    sort(id1 + 1, id1 + len1 + 1, cmp);
    sort(id2 + 1, id2 + len2 + 1, cmp);
    solve();
    swap(id1, id2); swap(len1, len2);
    solve();
    print(ans, '\n');
    return 0;
}