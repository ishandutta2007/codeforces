#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long LL;

const int N = 1e5 + 5, P = 1e9 + 7;

int n, m, f[N];

int main() {
    scanf("%d%d", &n, &m);
    f[0] = 2;
    for (int i = 1; i <= max(n, m); i++) {
        f[i] = f[i - 1];
        if (i > 1) (f[i] += f[i - 2]) %= P;
    }
    int t = f[m] - 2;
    int s = f[n];
    printf("%d\n", (t + s) % P);
    return 0;
}