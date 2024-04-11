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

int const N = 1e5 + 5;

int n;
int a[N];
ll S = 0;
ll pref[N];
ll suff[N];

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        S += a[i];
    }

    if(S % 2) {
        puts("NO");
        return 0;
    }

    for(int i = 1;i <= n;i++) {
        pref[i] = pref[i - 1] + a[i];
    }

    for(int i = n;i >= 1;i--) {
        suff[i] = suff[i + 1] + a[i];
    }

    for(int i = 1;i <= n;i++) {
        if(pref[i] == S / 2) {
            puts("YES");
            return 0;
        }
    }

    multiset< ll > L, R;

    for(int i = n;i > 1;i--) {
        R.insert(pref[i]);
    }

    for(int i = 1;i <= n;i++) {
        if(L.count(S / 2 + a[i]) || R.count(S / 2 + a[i])) {
            puts("YES");
            return 0;
        }
        L.insert(suff[i]);
        if(i < n) {
            R.erase(R.lower_bound(pref[i + 1]));
        }
    }

    puts("NO");

    return 0;
}