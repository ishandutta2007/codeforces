#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "debug.h"
#else
    #define dbg(...)
#endif // LOCAL

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;

    auto query1 = [&](int pos) {
        cout << "? 1 " << pos + 1 << endl;
        char c;
        cin >> c;
        return c;
    };

    auto query2 = [&](int l, int r) {
        cout << "? 2 " << l + 1 << ' ' << r + 1 << endl;
        int res;
        cin >> res;
        return res;
    };

    string ans(n, '?');
    int start = 0, have = 0;
    vector<int> last(26, -1);

    while (start < n) {
        char new_c = query1(start);
        ans[start] = new_c;
        last[new_c - 'a'] = start;
        have++;

        int l = start, r = n;
        while (r - l > 1) {
            int mid = (l + r) >> 1;
            (query2(0, mid) == have ? l : r) = mid;
        }

        for (int i = start + 1; i < r; i++) {
            vector<pair<int, char>> v;
            v.reserve(have);
            for (int j = 0; j < 26; j++) {
                if (last[j] != -1) v.emplace_back(last[j], 'a' + j);
            }
            sort(all(v));
            reverse(all(v));

            int l = -1, r = len(v) - 1;
            while (r - l > 1) {
                int mid = (l + r) >> 1;
                (query2(v[mid].first, i) == mid + 1 ? r : l) = mid;
            }
            ans[i] = v[r].second;
            last[ans[i] - 'a'] = i;
        }
        start = r;
    }
    cout << "! " << ans << endl;
}