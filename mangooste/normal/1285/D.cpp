#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

int get_ans(vector<int> &els, int bt) {
    vector<vector<int>> cnt(bt), not_cnt(bt);
    for (int i = 0; i < bt; i++)
        for (auto el : els)
            if (el & (1 << i))
                cnt[i].pb(el);
            else
                not_cnt[i].pb(el);
    int ans = (1 << bt);
    for (int i = bt - 1; i >= 0; i--) {
        int sz = cnt[i].size();
        if (sz == els.size() || sz == 0)
            continue;
        ans += min(get_ans(cnt[i], i), get_ans(not_cnt[i], i));
        break;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> cnt(30), not_cnt(30);
    for (auto &el : a) {
        cin >> el;
        for (int bt = 0; bt < 30; bt++)
            if (el & (1 << bt))
                cnt[bt].pb(el);
            else
                not_cnt[bt].pb(el);
    }
    for (int bt = 29; bt >= 0; bt--) {
        int sz = cnt[bt].size();
        if (sz == 0 || sz == n)
            continue;
        cout << min(get_ans(cnt[bt], bt), get_ans(not_cnt[bt], bt)) << '\n';
        return 0;
    }
    cout << "0\n";
}