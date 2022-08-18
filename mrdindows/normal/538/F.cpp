#include <bits/stdc++.h>
#define UN(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
#define FOR(i, a, b) for (int i(a), _B_##i(b); i < _B_##i; ++i)
#define CL(a, b) memset(a, b, sizeof a)
#define all(a) (a).begin(), (a).end()
#define REP(i, n) FOR(i, 0, n)
#define sz(a) int((a).size())
#define long int64_t
#define pb push_back
#define Y second
#define X first
#ifndef LOCAL
#define NDEBUG
#endif

using namespace std;

typedef pair<int, int> pii;

int n;
int a[200500];
vector<int> st[400500];

int count_less(const vector<int> &v, int than) {
    return lower_bound(all(v), than) - v.begin();
}

int count_less(int x, int y, int than) {
    int cnt = 0;
    for (x += n, y += n; x <= y; x = (x + 1) / 2, y = (y - 1) / 2) {
        if ( x & 1) cnt += count_less(st[x], than);
        if (~y & 1) cnt += count_less(st[y], than);
    }
    return cnt;
}

int main() {
    scanf("%d", &n);
    REP (i, n) scanf("%d", a + i);
    for (int i = 0; i < n; ++i)
        for (int j = i + n; j; j /= 2)
            st[j].pb(a[i]);
    REP (i, n + n)
        sort(all(st[i]));
    vector<int> res(n - 1);
    FOR (k, 1, n) {
        int m = (n - 2) / k + 1;
        REP (i, m) {
            int lo = i * k + 1;
            int hi = min(lo + k, n);
            res[k - 1] += count_less(lo, hi - 1, a[i]);
        }
    }
    for (int c : res)
        printf("%d ", c);
    puts("");
    return 0;
}