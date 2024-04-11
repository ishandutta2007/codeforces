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

    scanf("%d", &n);

    vec< int > a(n);

    for(int i = 0;i < n;i++) {
        scanf("%d", &a[i]);
        a[i]--;
    }

    vec< int > fen(n);

    int res = 0;

    for(int i = n - 1;i >= 0;i--) {
        for(int cur = a[i] - 1;cur >= 0;cur = (cur & (cur + 1)) - 1) {
            res ^= fen[cur];
        }
        for(int cur = a[i];cur < n;cur |= (cur + 1)) {
            fen[cur] ^= 1;
        }
    }

    if(n & 1) {
        puts(res ? "Petr" : "Um_nik");
    }else {
        puts(res ? "Um_nik" : "Petr");
    }

    return 0;
}