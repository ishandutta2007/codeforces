// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 1e5 + 5, L = 18;
const int INF = 0x3f3f3f3f;
LL f[L][N];
 
int k;



int phi[N], B, pr[N], tot;

LL p[N], s1[N][320], s2[N][320];

bool st[N];

LL inline c(int l, int r) {
    int t = r / l, z = r / t;
    LL sum = s2[r][1];
    if (t <= B) {
        return sum - (s2[r][t] - (z - l + 1) * p[t]);
    } else return sum - (s1[r][z] - (z - l + 1) * p[t]);
}

void inline prework(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) pr[++tot] = i, phi[i] = i - 1;
        for (int j = 1; pr[j] * i <= n; j++) {
            st[pr[j] * i] = 1;
            if (i % pr[j] == 0) {
                phi[pr[j] * i] = phi[i] * pr[j];
                break;
            }
            phi[pr[j] * i] = phi[i] * (pr[j] - 1);
        }
    }
    for (int i = 1; i <= n; i++) p[i] = p[i - 1] + phi[i];
    for (int x = 1; x <= n; x++) {
        for (int l = 1, r, t; l < x; l = r + 1) {
            t = (x / l), r = min((x / t), x - 1);
            LL w = p[t] * (r - l + 1);
            if (t <= B) s2[x][t] = w;
            else s1[x][r] = w;
        }
        for (int i = 1; i <= B; i++) s1[x][i] += s1[x][i - 1];
        s2[x][B] += s1[x][B];
        for (int i = B - 1; i; i--)
            s2[x][i] += s2[x][i + 1];
    }
}

void work(int l, int r, int x, int y) {
    if (l > r) return;
    if (x == y) {
        for (int i = l; i <= r; i++) {
            f[k][i] = f[k - 1][x] + c(x + 1, i);
        }
        return; 
    }
    int mid = (l + r) >> 1, z;
    for (int i = x; i <= y; i++) {
        if (f[k - 1][i] == INF || i >= mid) continue;
        LL gx = f[k - 1][i] + c(i + 1, mid);
        if (gx < f[k][mid]) f[k][mid] = gx, z = i;
    }
    work(l, mid - 1, x, z);
    work(mid + 1, r, z, y);
}

int main() {
    B = 319;
    prework(1e5);
    int n = 1e5;
    memset(f, 0x3f, sizeof f);
    f[0][0] = 0;
    for (k = 1; k <= 17; k++) {
        f[k][0] = 0;
        work(1, n, 0, n);
    }
    int Q; read(Q);
    while (Q--) {
        int n, k; read(n), read(k);
        k = min(k, 17);
        printf("%lld\n", f[k][n] + n);
    }
    return 0;
}