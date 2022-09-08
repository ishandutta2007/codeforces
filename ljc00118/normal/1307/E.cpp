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

const int N = 5005, md = 1e9 + 7;

vector <int> pos[N], cow[N];
int a[N];
int n, m, ans1, ans2;

int main() {
    read(n); read(m);
    for (int i = 1; i <= n; i++) read(a[i]), pos[a[i]].push_back(i);
    for (int i = 1; i <= m; i++) {
        int x, y;
        read(x); read(y);
        if (y > (int)pos[x].size()) continue;
        cow[x].push_back(y);
    }
    for (int i = 1; i <= n; i++) sort(cow[i].begin(), cow[i].end());
    cow[0].push_back(1); pos[0].push_back(0);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < (int)cow[i].size(); j++) {
            int now1 = (i != 0), now2 = 1, len = pos[i][cow[i][j] - 1];
            for (int k = 0; k < (int)cow[i].size(); k++) {
                if (j == k) continue;
                if (cow[i][k] + cow[i][j] <= (int)pos[i].size()) {
                    if (now1 == 1) now1 = 2;
                    else ++now2;
                } else break;
            }
            // if (i == 0 && j == 0) fprintf(stderr, "ok : now1 = %d, now2 = %d\n", now1, now2);
            for (int k = 1; k <= n; k++) {
                if (i == k) continue;
                int now = cow[k].size() - 1, _now1 = 0, _now2 = 1;
                for (int t = 0; t < (int)cow[k].size(); t++) {
                    if (pos[k][cow[k][t] - 1] > len) break;
                    while (now >= 0 && (pos[k][pos[k].size() - cow[k][now]] < len || cow[k][t] + cow[k][now] > (int)pos[k].size())) --now;
                    int cnt = now + 1 - (t <= now);
                    if (!cnt) {
                        if (_now1 == 2) continue;
                        if (_now1 == 1) ++_now2;
                        else _now1 = 1, _now2 = 1;
                    } else {
                        if (_now1 < 2) _now1 = 2, _now2 = cnt;
                        else _now2 += cnt;
                    }
                }
                for (int t = 0; t < (int)cow[k].size(); t++) {
                    if (pos[k][pos[k].size() - cow[k][t]] > len) {
                        if (_now1 == 1) ++_now2;
                        else if(_now1 == 0) _now1 = 1, _now2 = 1;
                    }
                }
                now1 += _now1; now2 = 1ll * now2 * _now2 % md;
            }
            // fprintf(stderr, "i = %d, j = %d, now1 = %d, now2 = %d\n", i, j, now1, now2);
            if (now1 < ans1) continue;
            if (now1 == ans1) {
                ans2 += now2;
                if (ans2 >= md) ans2 -= md;
            } else ans1 = now1, ans2 = now2;
        }
    }
    print(ans1, ' '); print(ans2, '\n');
    return 0;
}