#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 1000 * 1000 + 100000;
const int INF = 1000 * 1000 * 1000;

int f[N];
bool was[N];
int res = INF;

int main() {
    fill(f, f + N, INF);
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> a;
    for (int i = 0; i < k; i++) {
        int x;
        scanf("%d", &x);
        if (x == n) {
            puts("1");
            return 0;
        }
        if (!was[x])
            a.push_back(x);
        was[x] = true;
    }
    sort(a.rbegin(), a.rend());
    for (int x : a)
        for (int y : a)
            if (x < n && y > n) {
                int dx = n - x;
                int dy = y - n;
                int g = __gcd(dx, dy);
                dx /= g;
                dy /= g;
                res = min(res, dx + dy);
            }
    if (res == INF) {
        puts("-1");
        return 0;
    }
    int bound = (a[0] - n) * res;
    for (int p = 0; p < int(a.size()); p++) {
        int d = a[p] - n;
        if (d > 0) {
            f[d] = 1;
            for (int i = d; i <= bound; i++) {
                f[i] = min(f[i], f[i - d] + 1);
            }
        } else {
            d = -d;
            for (int i = bound - d; i >= 0; i--) {
                f[i] = min(f[i], f[i + d] + 1);
            }
        }
    }
    printf("%d\n", f[0]);
}