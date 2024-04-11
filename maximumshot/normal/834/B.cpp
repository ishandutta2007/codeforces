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

    int n, k;

    scanf("%d %d", &n, &k);

    char s[1000005];

    scanf("%s", s);

    int o = 0;

    vec< int > L(26, inf);
    vec< int > R(26, -inf);

    for(int x, i = 0;i < n;i++) {
        x = s[i] - 'A';
        L[x] = min(L[x], i);
        R[x] = max(R[x], i);
    }

    for(int x, i = 0;i < n;i++) {
        x = s[i] - 'A';
        if(L[x] == i) {
            o++;
        }
        if(o > k) {
            puts("YES");
            return 0;
        }
        if(R[x] == i) {
            o--;
        }
    }

    puts("NO");

    return 0;
}