#include <bits/stdc++.h>
using namespace std;

const int N = 1E5 + 5;

int n, u;
tuple<int, int, long long> ans = {0, 0, 0};
vector<int> ve;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> u;
        ve.push_back(u);
    }
    sort(ve.begin(), ve.end());
    for (int &v : ve) {
        for (int i = 0; i < 32; i++) {
            int cnt = 0;
            long long cur = 1LL << i;
            if (binary_search(ve.begin(), ve.end(), 0LL + cur + v)) {
                cnt++;
            }
            if (binary_search(ve.begin(), ve.end(), 2LL * cur + v)) {
                cnt++;
            }
            ans = max(ans, {cnt, v, cur});
        }
    }
    if (get<0>(ans) == 0) {
        cout << "1\n" << ve.back();
    } else {
        cout << get<0>(ans) + 1 << '\n';
        for (int i = 0; i <= get<0>(ans); i++) {
            cout << get<1>(ans) + i * get<2>(ans) << " ";
        }
    }
}