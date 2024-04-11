// Skyqwq
#include <bits/stdc++.h>

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

const int N = 205;

int n, a[N];
 
int main() {
    read(n);
    for (int i = 1; i <= 2 * n; i++) read(a[i]);
    int ans = 0;
    for (int i = 1; i <= 2 * n; i += 2) {
        int p = -1;
        for (int j = i + 1; j <= 2 * n; j++)
            if (a[j] == a[i]) p = j;
        while (p > i + 1) {
            swap(a[p], a[p - 1]), ++ans;
            --p;
        }
    }
    printf("%d\n", ans);
    return 0;
}