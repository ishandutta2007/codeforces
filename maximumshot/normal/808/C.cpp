#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 105;

int n, w;
pii a[N];
int b[N];
int res[N];

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &w);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }

    sort(a + 1, a + n + 1);

    for(int i = 1;i <= n;i++) {
        if((a[i].first + 1) / 2 > w) {
            puts("-1");
            return 0;
        }
        b[i] = (a[i].first + 1) / 2;
        w -= b[i];
    }

    int mx = 0;

    for(int i = 1;i <= n;i++) {
        int j = i;
        while(j <= n && a[i].first == a[j].first) j++;
        j--;
        for(int q = i;q <= j;q++) {
            if(b[q] < mx) {
                if(mx - b[q] > w) {
                    puts("-1");
                    return 0;
                }
                w -= (mx - b[q]);
                b[q] = mx;
            }
        }
        for(int q = i;q <= j;q++) {
            mx = max(mx, b[q]);
        }
    }

    for(int i = n;i >= 1;i--) {
        int mn = min(w, a[i].first - b[i]);
        b[i] += mn;
        w -= mn;
    }

    if(w > 0) {
        puts("-1");
        return 0;
    }

    for(int i = 1;i <= n;i++) {
        res[a[i].second] = b[i];
    }

    for(int i = 1;i <= n;i++) {
        printf("%d ", res[i]);
    }

    printf("\n");

    return 0;
}