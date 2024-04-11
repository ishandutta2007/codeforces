#include <bits/stdc++.h>

using namespace std;

#define ALL(x) begin(x), end(x)
#define vec vector

typedef long long ll;
typedef unsigned int ui;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = ll(1e18);

const int N = 2e5 + 5;

int n, a, b;
int x[N];
pii v[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d %d", &n, &a, &b);

    for(int i = 1;i <= n;i++) {
        scanf("%d %d %d", &x[i], &v[i].first, &v[i].second);
    }

    sort(v + 1, v + n + 1);

    ll res = 0;

    unordered_map< ll, int > cnt;

    for(int i = 1;i <= n;i++) {
        int j = i;
        while(j <= n && v[i] == v[j]) j++;
        j--;
        res += 1ll * cnt[v[i].second - 1ll * v[i].first * a] * (j - i + 1);
        cnt[v[i].second - 1ll * v[i].first * a] += j - i + 1;
        i = j;
    }

    printf("%lld\n", 2ll * res);

    return 0;
}