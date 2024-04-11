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

const int N = 1e5 + 5;

LL a, b, c, z;

int n, d[N], tot;

char s[N];
 
int main() {
 //    freopen("f.in", "r", stdin);
 // freopen("f.out", "w", stdout);
    int T; read(T);
    while (T--) {
        read(n); read(a), read(b), read(c);
        scanf("%s", s + 1); tot = 0;
        if (n == 1) {
            puts("0");
            continue;
        }
        int c1 = 0; z = 0;
        for (int i = 2; i <= n; i++) {
            if (s[i] == '1' && s[i - 1] == '1') c1++;
            if (s[i] == '0' && s[i - 1] == '0') z++;
        }
        if (z == n - 1) {
            printf("%lld\n", a);
            continue;
        }
        for (int i = 1; i <= n; i++) {
            if (s[i] == '1') continue;
            int j = i;
            while (j < n && s[j + 1] == '0') j++;
            if (i > 1 && j < n) {
                d[++tot] = j - i + 1;
            }
            i = j;
        }
        sort(d + 1, d + 1 + tot);
        LL ans = -9e18;
        LL t = 0;
        int ct = (s[1] == '0') + (s[n] == '0');
        for (int i = 0; i <= tot; i++) {
            if (i) t += d[i] - 1, z -= d[i] - 1;
            for (int x = 0; x <= ct; x++) {
                LL v = -(i + x) * c + t * a;
                LL bb = c1 + (i);
                if (bb < t + (i + x) - 1) continue;
                LL zm = min(bb, (i + x) + t + z);
                LL cc = zm;
                v += zm * b;
                if ((i + x) + t < zm) v += a * (zm - t - (i + x));
                if (zm != (i + x) + t - 1) {
                    if (zm < (i + x) + t + z) v += a;
                    else if (zm < bb) v += b, cc++;
                }
                //cout << x << " " << zm << " ??" << t << " " << z << " " << b << " "  << i << " " << v << "aaa\n";
                LL kk = min((LL)c1, cc);
                //cout << kk << "???" << t - 1 << endl;
                if (kk >= t)chkMax(ans, v);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}