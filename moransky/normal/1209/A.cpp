#include <iostream>
#include <cstdio>
#include <cstring>
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long LL;

using namespace std;

template <typename T> void inline chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void inline chkMin(T &x, T y) { if (y < x) x = y; }


template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}
 
template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}


const int N = 105;

int n, cnt[N];

int main() {
	memset(cnt, 0, sizeof cnt);
    scanf("%d", &n);
    while (n--) {
        int x; read(x);
        cnt[x]++;
    }
    int ans = 0;
    for (int i = 1; i <= 100; i++) {
        if (cnt[i]) {
            for (int j = i; j <= 100; j += i) cnt[j] = 0;
            ans++;
        }
    }
    printf("%d\n", ans);
	
}