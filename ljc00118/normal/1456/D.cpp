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
 
const int N = 5005;
 
pii a[N];
int l[N], r[N], tag[N];
int n;
 
void addseg(int id, int L, int R) {
    if (!tag[id]) {
        tag[id] = 1;
        l[id] = L;
        r[id] = R;
    } else {
        l[id] = min(l[id], L);
        r[id] = max(r[id], R);
    }
}
 
int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(a[i].first), read(a[i].second);
    sort(a + 1, a + n + 1);
    l[0] = r[0] = 0; tag[0] = 1;
    for (int i = 0; i < n; i++) {
        if (!tag[i]) continue;
        if (abs(a[i].second - a[i + 1].second) <= a[i + 1].first - a[i].first) {
            int free = (a[i + 1].first - a[i].first - abs(a[i].second - a[i + 1].second)) / 2;
            addseg(i + 1, min(l[i], min(a[i].second, a[i + 1].second) - free), max(r[i], max(a[i].second, a[i + 1].second) + free));
        }
        int last = a[i].first, lasx = a[i].second;
        for (int j = i + 1; j < n; j++) {
            if (j == i + 1 && l[i] <= a[j].second && a[j].second <= r[i]) goto cando;
            {
                int nowt = max(last + abs(lasx - a[j].second), j == i + 1 ? 0 : a[j - 1].first);
                if (nowt > a[j].first) break;
                last = nowt; lasx = a[j].second;
            }
            cando:;
            if (lasx < a[j + 1].second) {
                int dis = abs(lasx - a[j + 1].second);
                if (last + dis > a[j + 1].first) continue;
                int more = a[j + 1].first - last - dis;
                int R = min(a[j + 1].second + (a[j + 1].first - a[j].first), a[j + 1].second + more / 2), L;
                if (a[j].first - last <= (more + 1) / 2) L = lasx - more / 2;
                else L = a[j + 1].second - (a[j + 1].first - a[j].first);
                addseg(j + 1, L, R);
            } else {
                int dis = abs(lasx - a[j + 1].second);
                if (last + dis > a[j + 1].first) continue;
                int more = a[j + 1].first - last - dis;
                int L = max(a[j + 1].second - (a[j + 1].first - a[j].first), a[j + 1].second - more / 2), R;
                if (a[j].first - last <= (more + 1) / 2) R = lasx + more / 2;
                else R = a[j + 1].second + (a[j + 1].first - a[j].first);
                addseg(j + 1, L, R);
            }
        }
    }
    if (tag[n] || (tag[n - 1] && l[n - 1] <= a[n].second && a[n].second <= r[n - 1])) printf("YES\n");
    else printf("NO\n");
    return 0;
}