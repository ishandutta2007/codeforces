#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 200005;

int n, m;
pii p[N];
pii s[N];
int res[N];
int to[N];

bool solve() {

    scanf("%d %d", &n, &m);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &p[i].first), p[i].second = i;
        to[i] = -1;
    }
    for(int i = 1;i <= m;i++) {
        scanf("%d", &s[i].first), s[i].second = i;
        res[i] = -1;
    }

    sort(p + 1, p + n + 1);
    sort(s + 1, s + m + 1);

    int res1 = 0;
    int res2 = 0;

    for(int ITER = 0;ITER <= 30;ITER++) {
        for(int i = 1, j = 1;i <= n && j <= m;) {
            if(to[p[i].second] != -1) {
                i++;
                continue;
            }
            if(res[s[j].second] != -1) {
                j++;
                continue;
            }
            if(p[i].first == s[j].first) {
                to[p[i].second] = s[j].second;
                res[s[j].second] = ITER;
                res1++;
                res2 += ITER;
                i++;
                j++;
            }else if(p[i].first < s[j].first) i++;
            else j++;
        }
        for(int i = 1;i <= m;i++) {
            s[i].first = (s[i].first + 1) / 2;
        }
    }

    printf("%d %d\n", res1, res2);

    for(int i = 1;i <= m;i++) {
        if(res[i] == -1) res[i] = 0;
        printf("%d ", res[i]);
    }

    printf("\n");

    for(int i = 1;i <= n;i++) {
        if(to[i] == -1) to[i] = 0;
        printf("%d ", to[i]);
    }

    printf("\n");

    return true;
}

int main() {

#ifdef MY
    while(solve());
#else
    solve();
#endif

    return 0;
}