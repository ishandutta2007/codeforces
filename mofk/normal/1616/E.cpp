#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

typedef
tree<
  int,
  null_type,
  less<int>,
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_set;

const long long linf = 1e18;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        string a, b;
        cin >> n >> a >> b;
        vector<vector<int>> pos(26, vector<int>());
        ordered_set os;
        for (int i = 0; i < n; ++i) os.insert(i);
        for (int i = n - 1; i >= 0; --i) {
            pos[a[i] - 'a'].push_back(i);
        }
        long long ans = linf, cur = 0;
        for (int i = 0; i < n; ++i) {
            int choose = n + 1;
            for (int c = 0; c < b[i] - 'a'; ++c) {
                if (pos[c].empty()) continue;
                choose = min(choose, pos[c].back());
            }
            if (choose < n) {
                ans = min(ans, cur + os.order_of_key(choose));
            }
            if (pos[b[i] - 'a'].empty()) {
                break;
            }
            else {
                int j = pos[b[i] - 'a'].back();
                pos[b[i] - 'a'].pop_back();
                cur += os.order_of_key(j);
                os.erase(j);
            }
        }
        if (ans >= linf) ans = -1;
        cout << ans << '\n';
    }
    return 0;
}