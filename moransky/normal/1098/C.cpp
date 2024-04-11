// Skyqwq
#include <iostream>
#include <cstdio>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}
 
template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(-x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 1e5 + 5;

int n;

LL S;

int cnt[N];
 
bool inline check(int x) {
    for (int i = 1; i <= n; i++) cnt[i] = 1;
    LL t = n * (n + 1ll) / 2 - S;
    int i = 2, j = n;
    while (t) {
        while (cnt[i] == cnt[i - 1] * x) i++;
        while (!cnt[j]) --j;
        if (i >= j) return 0;
        if (j - i < t) {
            t -= j - i, cnt[j]--, cnt[i]++;
        } else {
            cnt[j]--, cnt[j - t]++;
            return 1;
        }
    }
    return 1;
}

int main() {
    read(n), read(S);
    if (S > n * (n + 1ll) / 2 || S < 2 * n - 1) { puts("No"); return 0; }
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    check(r);
    puts("YES");
    int s = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= cnt[i]; j++)
            printf("%d ", s + (j - 1) / r);
        s += cnt[i - 1];
    }
	return 0;
}