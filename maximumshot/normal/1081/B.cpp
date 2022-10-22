#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long double, long double > pdd;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int mod = 998244353;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n;

    scanf("%d", &n);

    vector< int > a(n);

    for(int i = 0;i < n;i++) {
        scanf("%d", &a[i]);
        a[i] = n - a[i];
    }

    vector< vector< int > > cnt(n + 1);

    for(int i = 0;i < n;i++) {
        cnt[ a[i] ].push_back(i);
    }

    int cur = 1;

    vector< int > b(n);

    for(int x = 1;x <= n;x++) {
        int sz = (int)cnt[x].size();
        if(!sz) continue;
        if(sz % x) {
            puts("Impossible");
            return 0;
        }
        for(int i = 0;i < sz;i += x, cur++) {
            for(int j = i;j < i + x;j++) {
                int id = cnt[x][j];
                b[id] = cur;
            }
        }
    }

    int ok = 1;

    vector< int > tot(n + 1);

    for(int i = 0;i < n;i++) {
        tot[b[i]]++;
    }

    for(int i = 0;i < n;i++) {
        if(tot[b[i]] != a[i]) {
            puts("Impossible");
            return 0;
        }
    }

    puts("Possible");

    for(int x : b) {
        printf("%d ", x);
    }

    printf("\n");

    return 0;
}