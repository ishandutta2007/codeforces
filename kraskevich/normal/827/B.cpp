#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

ll calc_nodes(ll diam, ll leaves) {
    ll large = (diam + 1) / 2 + 1;
    ll small = diam / 2 + 1;
    return large + (small - 1) * (leaves - 1);
}
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    int d = 2;
    while (calc_nodes(d, k) < n)
        ++d;
    int large = (d + 1) / 2;
    int small = d / 2;
    int cur = 1;
    int max_len = large;
    vector<pii> ans;
    vector<int> roots(k);
    for (int i = 0; i < k; i++) {
        ans.push_back({0, cur});
        roots[i] = cur;
        ++cur;
    }
    for (int i = 0; i < k; i++) {
        int last = roots[i];
        for (int j = 2; j <= max_len; j++, cur++) {
            if (cur < n)
                ans.push_back({last, cur});
            last = cur;
        }
        max_len = small;
    }
    cout << d << "\n";
    for (auto p : ans)
        cout << p.first + 1 << " " << p.second + 1 << "\n";
}