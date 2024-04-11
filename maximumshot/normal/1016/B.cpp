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

const int N = 1005;

char buffer[N];

inline void read_string(string &s) {
    scanf("%s", buffer);
    s = buffer;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n, m, q;
    string a, b;

    scanf("%d %d %d", &n, &m, &q);

    read_string(a);
    read_string(b);

    vec< int > pr(n);

    for(int i = 0;i < n;i++) {
        if(i) pr[i] = pr[i - 1];
        if(i + m - 1 < n && a.substr(i, m) == b) {
            pr[i]++;
        }
    }

    for(int l, r, i = 0;i < q;i++) {
        scanf("%d %d", &l, &r);
        l--, r--;
        if(r - l + 1 < m) {
            puts("0");
        }else {
            r -= (m - 1);
            printf("%d\n", pr[r] - (l ? pr[l - 1] : 0));
        }
    }

    return 0;
}