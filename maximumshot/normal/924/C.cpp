#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 1e5 + 5;

int n;
int m[N];
int a[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    ll res = 0;

    int last = 0;

    for(int i = 1;i <= n;i++) {
        scanf("%d", &m[i]);
        a[i] = a[i - 1];
        a[i] = max(a[i], m[i] + 1);
    }

    for(int i = n - 1;i >= 1;i--) {
        if(a[i] + 1 < a[i + 1]) {
            a[i] = a[i + 1] - 1;
        }
    }

    for(int i = 1;i <= n;i++) {
        res += a[i] - m[i] - 1;
    }

    cout << res << "\n";

    return 0;
}