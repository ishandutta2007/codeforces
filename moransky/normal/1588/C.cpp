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

const int N = 3e5 + 5;

int n, a[N];

struct E{
    LL b[N], d[N];
    int top, s[N], R[N], tot, id;
    int inline get(LL x) {
        return lower_bound(d + 1, d + 1 + tot, x) - d;
    }
    vector<int> p[N];
    void inline work() {
        top = tot = 0;
        for (int i = 1; i <= n + 1; i++) s[i] = d[i] = R[i] = 0, p[i].clear();
        for (int i = 1; i <= n; i++) b[i] += b[i - 1];
        s[0] = n + 1;
        for (int i = n; i >= 0; i--) {
            if ((i & 1) == id) {
                while (top && b[s[top]] >= b[i]) top--;
                R[i] = s[top];
                s[++top] = i;
            } else {
                if (!top || b[s[1]] >= b[i]) R[i] = n + 1;
                else {
                    int l = 1, r = top;
                    while (l < r) {
                        int mid = (l + 1 + r) >> 1;
                        if (b[s[mid]] < b[i]) l = mid;
                        else r = mid - 1;
                    } 
                    R[i] = s[r];
                }
            }
        }
        for (int i = 1; i <= n; i++) d[i] = b[i];
        d[tot = n + 1] = 0;
        sort(d + 1, d + 1 + tot);
        tot = unique(d + 1, d + 1 + tot) - d - 1;
        for (int i = 1; i <= n; i++) {
            if ((i & 1) == id) {
              int w = get(b[i]);
                p[w].pb(i);
            }
           
        }
       // puts("");
    }
    int inline get(int i, int r) {
        if (i > r) return 0;
        int w = get(b[i - 1]);
        int nx = upper_bound(p[w].begin(), p[w].end(), r) - p[w].begin();
        int ny = lower_bound(p[w].begin(), p[w].end(), i) - p[w].begin();
        return nx - ny;
    }
} t[2];

int main() {
    int T; read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) read(a[i]);
        for (int i = 1; i <= n; i++) {
            t[0].b[i] = a[i];
            t[1].b[i] = a[i];
            if (i & 1) t[0].b[i] *= -1;
            else t[1].b[i] *= -1;
        }
        t[1].id = 1;
        t[0].work(), t[1].work();
        LL ans = 0;
        for (int i = 1; i <= n; i++) {
            int mn = min(t[0].R[i - 1], t[1].R[i - 1]) - 1;
          //  cout << mn << "??\n";
            ans += t[0].get(i, mn);
            ans += t[1].get(i, mn);
         //   cout << ans << endl;
        } 
        printf("%lld\n", ans);
    }
    return 0;
}