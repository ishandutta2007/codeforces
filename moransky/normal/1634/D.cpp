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

const int N = 1e3 + 5;

int n, b[7], d[7], t, c[7], a[N];
 
int ct = 0;

map<vector<int>, int > W;

int inline ask(int i, int j, int k) {
    vector<int> B; B.pb(i), B.pb(j), B.pb(k);
    sort(B.begin(), B.end());
    if (W.count(B)) return W[B];
    printf("? %d %d %d\n", i, j, k);
    fflush(stdout);
    int x; read(x);  
    return W[B] = x;
}

int main() {
    int T; read(T);
    while (T--) {
        W.clear();
        read(n); ct = 0;
        
        int mx = -2e9, p = -1;
        for (int i = 3; i <= n; i++) {
            int o = ask(1, 2, i);
            if (chkMax(mx, o)) {
                p = i;
            }
        }
        int q = 3;
        if (p == q) q++;
        bool fl = 1;
        int la = -1;
        mx = -2e9;
        int nq = -1;
        if (n != 5) {
            for (int i = 3; i <= n; i++) {
                if (i != p && i != q) {
                    int o = ask(p, q, i);
                    if (chkMax(mx, o)) {
                        nq = i;
                    }
                    if (la != -1 && o != la) fl = 0;
                    la = o;
                }
            }
            if (fl) nq = q;
            q = nq;
        } else {
            int c[2] = { 0, 0 };
            t = 0;
            for (int i = 3; i <= n; i++)
                if (i != p) c[t++] = i;
            int A = ask(1, c[0], p), B = ask(1, c[1], p);
            if (A > B) q = c[0];
            else q = c[1];
        }
        int nmx = mx;
        mx = -2e9;
        d[0] = 1, d[1] = 2, d[2] = p, d[3] = q;
        for (int i = 0; i < 4; i++) {
            int c[3] = { 0, 0, 0 };
            int t = 0;
            for (int j = 0; j < 4; j++) {
                if (i != j) c[t++] = d[j];
            }
            b[i] = ask(c[0], c[1], c[2]);
            chkMax(mx, b[i]);
        }
        int cnt[4] = { 0, 0, 0, 0 };
        for (int i = 0; i < 4; i++) {
            if (b[i] == mx) {
                for (int j = 0; j < 4; j++) {
                    if (i != j) cnt[j]++;
                }
            }
        }
        int qmx = mx;
        mx = -2e9;
        for (int i = 0; i < 4; i++) {
            chkMax(mx, cnt[i]);
        }
        t = 0;
        for (int i = 0; i < 4; i++)
            if (mx == cnt[i]) c[++t] = d[i];
        //assert(ct <= 2 * n - 2);
        if (t == 1) c[2] = c[1];
        printf("! %d %d\n", c[1], c[2]);
        //assert(c[1] == ps || c[2] == ps);
        fflush(stdout);
    }
    return 0;
}