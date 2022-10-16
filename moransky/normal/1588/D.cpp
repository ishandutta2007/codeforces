// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 11, M = 110, S = 56;

int n, R[M][M][S], f[M][1 << 9], l;

int pos[M][M][2];
int w[M][M], cnt[M];

PII pre[M][1 << 9];

char s[M];

int inline get(char c) {
    if (c >= 'a' && c <= 'z') return c - 'a' + 1;
    return c - 'A' + 26 + 1;
}

void print(int i, int j) {
    if (i == 0) return;
    PII pr = pre[i][j];
    print(pr.fi, pr.se);
    putchar(s[i]);
}

int main() {
    int T; read(T);
    while (T--) {
        memset(R, 0, sizeof R);
        memset(pos, 0, sizeof pos);
        memset(w, 0, sizeof w);
        memset(pre, 0, sizeof pre);
        read(n);
        for (int i = 0; i < n; i++) {
            scanf("%s", s + 1);
            l = strlen(s + 1);
            memset(cnt, 0, sizeof cnt);
            for (int j = 1; j <= l; j++) {
                int v = get(s[j]);
                w[i][j] = cnt[v];
                pos[i][v][cnt[v]] = j;
                cnt[v]++;
            }
            for (int j = l; j; j--) {
                int v = get(s[j]);
                for (int k = 1; k < S; k++)
                    R[i][j][k] = R[i][j + 1][k];
                R[i][j][v] = j;
            }
        }
        int ans = 0;
        memset(f, 0xcf, sizeof f);
        f[0][0] = 0;
        int A = 0, B = 0;
        for (int i = 0; i <= l; i++) {
            int ch = get(s[i]);
            if (i == 0) ch = 0;
            for (int j = 0; j < (1 << (n - 1)); j++) {
                if (f[i][j] < 0) continue;
                if (chkMax(ans, f[i][j])) A = i, B = j;
               //cout << i << " " << j << " " << f[i][j] << endl;
                for (int k = 1; k <= 52; k++) {
                    if (!R[n - 1][i + 1][k]) continue;
                    int ni = R[n - 1][i + 1][k], ne = 0;
                    //cout << ni << " ??" << ne << endl;
                    bool o = 1;
                    for (int p = 0; p + 1 < n; p++) {
                        int q = pos[p][ch][j >> p & 1];
                        //cout << p << " " << q << "..." << k << "..." << endl;
                        if (!R[p][q + 1][k]) {
                            o = 0;
                            break;
                        }
                        int pt = R[p][q + 1][k];
                    //    cout << " ntc " << pt << endl;
                        if (w[p][pt]) ne |= 1 << p;
                    }
                    if (o) {
                        if (chkMax(f[ni][ne], f[i][j] + 1))
                            pre[ni][ne] = mp(i, j);
                    // cout << " ci " << k << " " << ni << " " << ne << endl;
                    }
                }
            }
        }
        
        printf("%d\n", ans);
        print(A, B);
        puts("");
    }
    return 0;
}