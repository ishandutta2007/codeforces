#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

int const inf = 1e9;
ll const inf64 = 1e18;

int const N = 1e5 + 5;

int n;
int p, q, r;
int a[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#else
#endif

    scanf("%d %d %d %d", &n, &p, &q, &r);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    ll s1 = LLONG_MIN;
    ll s2 = LLONG_MIN;
    ll s3 = LLONG_MIN;

    for(int i = n;i >= 1;i--) {
        s1 = max(s1, 1ll * a[i] * r);
        s2 = max(s2, s1 + 1ll * a[i] * q);
        s3 = max(s3, s2 + 1ll * a[i] * p);
    }

    cout << s3 << "\n";

    return 0;
}