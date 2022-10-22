#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n;

    cin >> n;

    vec< int > a(2 * n);

    for(int i = 0;i < 2 * n;i++) cin >> a[i];

    int res = 0;

    for(int i = 0;i < 2 * n;i += 2) {
        int j = i + 1;
        while(a[j] != a[i]) j++;
        while(j > i + 1) {
            res++;
            swap(a[j], a[j - 1]);
            j--;
        }
    }

    cout << res << "\n";

    return 0;
}