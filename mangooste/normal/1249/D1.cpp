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

using ll = long long;
using namespace std;

// #define int long long
#define all(a) a.begin(), a.end()

struct one {
    int num, L, R, type;

    one(int num = -1, int L = 0, int R = 0, int type = 0) :
        num(num), L(L), R(R), type(type)
    {}
};

int n, k, mx;
vector<pair<int, int>> segs;
vector<ll> fenw;
vector<vector<one>> evs;
set<pair<int, int>> open;
vector<int> ans;

ll get(int pos) {
    ll ans = 0;
    for (; pos >= 0; pos &= pos + 1, pos--)
        ans += fenw[pos];
    return ans;
}

void update(int pos, int del) {
    for (; pos < mx; pos |= pos + 1)
        fenw[pos] += del;
}

void update(int L, int R, int del) {
    update(L, del);
    update(R + 1, -del);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    segs.resize(n);
    for (auto &i : segs) 
        cin >> i.first >> i.second, i.first--, i.second--;
    mx = segs[0].second;
    for (int i = 1; i < n; i++)
        mx = max(mx, segs[i].second);
    mx += 2;
    fenw.resize(mx);
    evs.resize(mx);
    for (int i = 0; i < n; i++) {
        update(segs[i].first, segs[i].second, 1);
        evs[segs[i].first].push_back(one(i, segs[i].first, segs[i].second, 1));
        evs[segs[i].second].push_back(one(i, segs[i].first, segs[i].second, 2));
    }
    for (int i = 0; i < mx; i++) {
        int cur_val = get(i);
        for (auto j : evs[i])
            if (j.type == 1)
                open.insert({-j.R, j.num});
        for (int j = cur_val; j > k; j--) {
            int cur_num = open.begin()->second;
            ans.push_back(cur_num);
            update(segs[cur_num].first, segs[cur_num].second, -1);
            open.erase(open.begin());
        }
        for (auto j : evs[i])
            if (j.type == 2)
                open.erase({-j.R, j.num});
    }
    cout << ans.size() << '\n';
    for (auto i : ans)
        cout << i + 1 << ' ';
    cout << '\n';
}