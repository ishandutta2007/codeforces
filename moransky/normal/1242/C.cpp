#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

template <typename T> void inline chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void inline chkMin(T &x, T y) { if (y < x) x = y; }

const int M = 15, N = 5000;

int k, n[M], a[M][N], c[N], t, d[N], use[M], pt[M];

LL s = 0, sum[M];

struct Pl{
    int i, j, c;
};

vector<Pl> e[1 << M];

bool vis[1 << M], f[1 << M];

map<LL, PII> cnt;

void inline work(int s) {
    if (s == 0) return;
    for (int i = s; i; i = (i - 1) & s) {
        if (vis[i] && f[s ^ i]) {
            for (int j = 0; j < e[i].size(); j++) {
                Pl v = e[i][j];
                pt[v.i] = v.j;
                use[v.i] = v.c;
            }
            work(s ^ i);
            return;
        }
    }
}

int main() {
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", n + i);
        for (int j = 0; j < n[i]; j++)
            scanf("%d", &a[i][j]), s += a[i][j], cnt[a[i][j]] = mp(i, j), sum[i] += a[i][j];
    }
    if (s % k) {
        puts("No");
        return 0;
    }
    s /= k;
    for (int i = 0; i < k; i++) {
        if (sum[i] == s) {
            vis[1 << i] = 1;
            //cout << " ji huo danyi " << i << endl;
            e[1 << i].pb((Pl) { i, i, a[i][0] });
            continue;
        }
        for (int j = 0; j < n[i]; j++) {
            t = 0;
            for (int u = 0; u < k; u++) d[u] = -1;
            d[i] = j;
            int p = i;
            bool fl = 1;
            int st = 0;
            while (1) {
                st |= 1 << p;
                c[t++] = p;
               // cout << i << " " << j << " " << p << " ???? \n";
                LL nd = s - (sum[p] - a[p][d[p]]);
               // cout << nd << " !!!" << endl;
                if (!cnt.count(nd)) {
                    fl = 0;
                    break;
                }
                PII v = cnt[nd];
                if (d[v.fi] == -1){
                    p = v.fi;
                    d[p] = v.se;
                } else {
                    if (d[v.fi] == v.se && v.fi == c[0]) break;
                    else {
                        fl = 0;
                        break;
                    }
                }
            }
            if (fl && !vis[st]) {
                vis[st] = 1;
                for (int i = 0; i < t; i++) {
                    e[st].pb((Pl) { c[i], c[(i - 1 + t) % t], a[c[i]][d[c[i]]] });
                }
//                cout << st << " jihuo " << endl;
//                for (auto v: e[st]) {
//                    cout << v.i << " " << v.j << " " << v.c << endl;
//                }
//                puts("--");
            }
        }
    }
    f[0] = 1;
    
    for (int i = 1; i < (1 << k); i++) {
        for (int j = i; j; j = (j - 1) & i) {
            if (vis[j]) {
                f[i] |= f[i ^ j];
                if (f[i]) break;
            }
        }
    }
    
    int st = (1 << k) - 1;
    if (!f[st]) puts("No");
    else {
        puts("Yes");
        work(st);
        for (int i = 0; i < k; i++) {
            printf("%d %d\n", use[i], pt[i] + 1);
        }
    }
    return 0;
}