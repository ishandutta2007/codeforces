#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef vector <int> vi;
#define fir first
#define sec second
template <typename __Tp> void read(__Tp &x) {
    int f = 0; x = 0; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
    for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
    if (f) x = -x;
}
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &...y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ...y) { write(x), write(y...); }

const int maxn = 2e5 + 10;
int n, q, a[maxn];

struct ST {
    pii mn[maxn][20];
    int lg[maxn];
    void build(int *a) {
        for (int i = 2; i <= n; ++i) lg[i] = lg[i >> 1] + 1;
        for (int i = 1; i <= n; ++i) mn[i][0] = pii(a[i], i);
        for (int j = 1; j < 20; ++j)
            for (int i = 1; i + (1 << j) - 1 <= n; ++i)
                mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
    }
    pii ask(int l, int r) {
        int i = lg[r - l + 1];
        return min(mn[l][i], mn[r - (1 << i) + 1][i]);
    }
} tr3, tr4;

int cnt[maxn], smx[maxn], tmx, smn[maxn], tmn;
int mr3[maxn], mr4[maxn];
array <int, 3> a3[maxn];
array <int, 4> a4[maxn];

int main() {
    read(n, q);
    for (int i = 1; i <= n; ++i) read(a[i]);
    memset(mr3, 0x3f, sizeof mr3);
    memset(mr4, 0x3f, sizeof mr4);
    for (int l = 1, r; l <= n; l = r) {
        for (r = l; r <= n && a[r] == a[l]; ++r);
        if (l > 1 && r <= n && (a[l] > a[l - 1]) == (a[r - 1] > a[r]))
            mr3[l - 1] = r, a3[l - 1][0] = l - 1, a3[l - 1][1] = l, a3[l - 1][2] = r;
    }
    set <int> pos;
    smx[0] = smn[0] = n + 1;
    for (int i = n; i >= 1; --i) {
        while (tmx && a[i] > a[smx[tmx]]) {
            if (--cnt[smx[tmx]] == 0) pos.insert(smx[tmx]);
            --tmx;
        }
        while (tmn && a[i] < a[smn[tmn]]) {
            if (--cnt[smn[tmn]] == 0) pos.insert(smn[tmn]);
            --tmn;
        }
        smx[++tmx] = smn[++tmn] = i, cnt[i] = 2;
        int l = 1, r = tmn, mid, pmx = tmx, pmn = tmn;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (a[i] == a[smn[mid]]) r = mid - 1, pmn = mid;
            else l = mid + 1;
        }
        l = 1, r = tmx;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (a[i] == a[smx[mid]]) r = mid - 1, pmx = mid;
            else l = mid + 1;
        }
        auto it = pos.lower_bound(max(smx[pmx - 1], smn[pmn - 1]));
        if (it != pos.end()) {
            int j = *it;
            l = 1, r = tmn, pmn = tmn;
            while (l <= r) {
                mid = (l + r) >> 1;
                if (smn[mid] < j) pmn = mid, r = mid - 1;
                else l = mid + 1;;
            }
            l = 1, r = tmx, pmx = tmx;
            while (l <= r) {
                mid = (l + r) >> 1;
                if (smx[mid] < j) pmx = mid, r = mid - 1;
                else l = mid + 1;
            }
            mr4[i] = j;
            a4[i][0] = i, a4[i][1] = smn[pmn], a4[i][2] = smx[pmx], a4[i][3] = j;
            sort(a4[i].begin(), a4[i].end());
        }
    }
    tr3.build(mr3), tr4.build(mr4);
    while (q--) {
        int l, r; read(l, r);
        pii p3 = tr3.ask(l, r), p4 = tr4.ask(l, r);
        if (p4.fir <= r) {
            write(4, '\n');
            for (int x : a4[p4.sec]) write(x, ' ');
            write('\n'); continue;
        }
        if (p3.fir <= r) {
            write(3, '\n');
            for (int x : a3[p3.sec]) write(x, ' ');
            write('\n'); continue;
        }
        write(0, '\n');
    }
	return 0;
}