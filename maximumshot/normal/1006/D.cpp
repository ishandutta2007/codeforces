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
    string a, b;

    cin >> n >> a >> b;

    int res = 0;

    if(n % 2 && a[n / 2] != b[n / 2]) res++;

    for(int i = 0;i < n / 2;i++) {
        char x, y, z, w;
        x = a[i];
        y = a[n - 1 - i];
        z = b[i];
        w = b[n - 1 - i];
        if(x > y) swap(x, y);
        if(z > w) swap(z, w);
        if(z == w) {
            if(x != y) res++;
        }else {
            if(x != z && x != w) res++;
            if(y != z && y != w) res++;
            if(x == y && (x == z || x == w)) res++;
        }
    }

    printf("%d\n", res);

    return 0;
}