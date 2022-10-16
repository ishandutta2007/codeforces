#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
ordered_set;

int n;
long long ans;
pair <int, int> a[200005];

bool cmp(pair <int, int> x, pair <int, int> y) {
    return x.second > y.second;
}

set <int> up;
ordered_set os;

void work(void) {
    int last = 0;
    for (auto x: up) {
        int cnt = os.order_of_key(x) - os.order_of_key(last + 1);
        ans -= 1ll * cnt * (cnt + 1) / 2;
        last = x;
    }
    int cnt = os.size() - os.order_of_key(last + 1);
    ans -= 1ll * cnt * (cnt + 1) / 2;
    for (auto x: up) os.insert(x);
    int sz = os.size();
    ans += 1ll * sz * (sz + 1) / 2;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i].first >> a[i].second;
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; ++i) {
        if (a[i].second != a[i-1].second) {
            work();
            up.clear();
        }
        up.insert(a[i].first);
    }
    work();
    cout << ans << endl;
    return 0;
}