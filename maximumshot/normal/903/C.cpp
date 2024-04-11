#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
//#include "optimization.h"

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;
typedef long double ld;

#define info(x) cerr << #x << " = " << x << endl
#define vec vector
#define ALL(x) (x).begin(), (x).end()

int const inf = 1e9;
ll const inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n;

    scanf("%d", &n);

    vector< int > a(n);

    for(int& x : a) {
        scanf("%d", &x);
    }

    sort(ALL(a));

    multiset< int > q;

    for(int i = n - 1;i >= 0;i--) {
        if(q.empty()) {
            q.insert(a[i]);
            continue;
        }
        auto fnd = q.upper_bound(a[i]);
        if(fnd == q.end()) {
            q.insert(a[i]);
        }else {
            q.erase(fnd);
            q.insert(a[i]);
        }
    }

    printf("%d\n", (int)q.size());

    return 0;
}