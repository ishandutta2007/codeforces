#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    for (int i = 0; i < n; ++i)
        cin >> c[i];

    for (auto k : c) {
        b.push_back(k);
    }

    map<int, int> whereb;
    map<int, int> wherec;
    for (int i = (int)b.size() - 1; i >= 0; --i)
        whereb[b[i]] = i;
    for (int i = (int)c.size() - 1; i >= 0; --i)
        wherec[c[i]] = i;

    vector<bool> first_in_a(a.size(), false);
    vector<bool> first_in_b(b.size(), false);
    set<int> ina, inb;
    for (int i = 0; i < a.size(); ++i) {
        if (!ina.count(a[i])) {
            ina.insert(a[i]);
            first_in_a[i] = true;
        }
    }
    for (int i = 0; i < b.size(); ++i) {
        if (!inb.count(b[i])) {
            inb.insert(b[i]);
            first_in_b[i] = true;
        }
    }

    set<pair<int, int>> maxs;
    multiset<int> res;

    maxs.emplace(1e9, 0);
    maxs.emplace(-1, 1e9 + 5);
    res.insert(maxs.begin()->first + next(maxs.begin())->second + 1);

    auto del = [&](pair<int, int> p) {
        auto it = maxs.find(p);
        assert(it != maxs.end());
        auto inext = next(it);
        auto iprev = prev(it);

        res.erase(res.find(iprev->first + it->second + 1));
        res.erase(res.find(it->first + inext->second + 1));
        maxs.erase(it);
        res.insert(iprev->first + inext->second + 1);
    };

    auto add = [&](pair<int, int> p) {
        auto it = maxs.lower_bound(make_pair(p.first, -5));
        if (it->second >= p.second) return;
        if (it->first == p.first) {
            ++it;
        }
        while (prev(it)->second <= p.second)
            del(*prev(it));

        maxs.insert(p);
        it = maxs.find(p);
        auto inext = next(it);
        auto iprev = prev(it);

        res.insert(iprev->first + it->second + 1);
        res.insert(it->first + inext->second + 1);
        res.erase(res.find(iprev->first + inext->second + 1));
    };

    for (int i = 0; i < b.size(); ++i) {
        if (first_in_b[i] && !ina.count(b[i])) {
            int inc = 1e9;
            if (wherec.count(b[i]))
                inc = wherec[b[i]] + 1;
            add({i, inc});
        }
    }

    int ans = n + *res.begin();

    for (int i = n - 1; i >= 0; --i) {
        if (first_in_a[i]) {
            if (!inb.count(a[i])) break;
            int inc = 1e9;
            if (wherec.count(a[i]))
                inc = wherec[a[i]] + 1;
            add({whereb[a[i]], inc});
        }
        ans = min(ans, i + *res.begin());
    }

    cout << ans << '\n';

    return 0;
}