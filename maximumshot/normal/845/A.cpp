#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n;

    cin >> n;

    vec< int > a(n+n);

    for(int i = 0;i < n+n;i++) {
        cin >> a[i];
    }

    sort(ALL(a));

    if(*max_element(a.begin(), a.begin() + n) < *min_element(a.begin() + n, a.end())) {
        cout << "YES\n";
    }else {
        cout << "NO\n";
    }

    return 0;
}