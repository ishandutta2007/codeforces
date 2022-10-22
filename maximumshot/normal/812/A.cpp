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

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    int l[4];
    int s[4];
    int r[4];
    int p[4];

    for(int i = 0;i < 4;i++) {
        cin >> l[i] >> s[i] >> r[i] >> p[i];
    }

    for(int i = 0;i < 4;i++) {
        if(p[i] && (l[i] || s[i] || r[i] || l[(i + 1) % 4] || s[(i + 2) % 4] || r[(i + 3) % 4])) {
            puts("YES");
            return 0;
        }
    }

    puts("NO");

    return 0;
}