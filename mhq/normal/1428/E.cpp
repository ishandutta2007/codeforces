#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, k;
const int maxN = 1e5 + 10;
int a[maxN];
ll f(int val, int cnt) {
    assert(val >= cnt);
    int small = val / cnt;
    int big = (val + cnt - 1) / cnt;
    int cnt_big = val % cnt;
    return (1LL * cnt_big * big * big + 1LL * (cnt - cnt_big) * small * small);
}
int cur[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    ll cost = 0;
    priority_queue<pair<ll,int>> q;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cost += 1LL * a[i] * a[i];
        cur[i] = 1;
        if (a[i] > 1) {
            q.push(make_pair(f(a[i], 1) - f(a[i], 2), i));
        }
    }
    for (int step = 0; step < k - n; step++) {
        assert(!q.empty());
        auto it = q.top();
        q.pop();
        cost += -it.first;
        int ind = it.second;
        cur[ind]++;
        if (a[ind] > cur[ind]) {
            q.push(make_pair(f(a[ind], cur[ind]) - f(a[ind], cur[ind] + 1), ind));
        }
    }
    cout << cost;
    return 0;
}