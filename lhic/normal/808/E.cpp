#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

const int MAXN = 310000;
int n, m;
ll g1[MAXN];
ll g2[MAXN];
ll g3[MAXN];
ll go[MAXN];
int c1, c2, c3;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        int w, c;
        scanf("%d%d", &w, &c);
        if (w == 1) {
            g1[c1++] = c;
        }
        else if (w == 2) {
            g2[c2++] = c;
        }
        else {
            g3[c3++] = c;
        }
    }
    sort(g1, g1 + c1);
    sort(g2, g2 + c2);
    sort(g3, g3 + c3);
    reverse(g1, g1 + c1);
    reverse(g2, g2 + c2);
    reverse(g3, g3 + c3);
    int n1 = 0;
    int n2 = 0;
    ll now = 0;
    for (int i = 1; i <= m; ++i) {
        now += g1[n1];
        ++n1;
        if (n1 >= 2 && g2[n2] >= g1[n1 - 1] + g1[n1 - 2]) {
            now -= g1[n1 - 1];
            now -= g1[n1 - 2];
            n1 -= 2;
            now += g2[n2];
            ++n2;
        }
        go[i] = now;
    }
    ll now2 = 0;
    ll ans = 0;
    for (int i = 0; i <= c3; ++i) {
        if (3 * i > m)
            break;
        ans = max(ans, now2 + go[m - 3 * i]);
        now2 += g3[i];
    }
    cout << ans << "\n";
    return 0;
}