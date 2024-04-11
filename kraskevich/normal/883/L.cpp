#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = (int)1e9;

struct Car {
    int x = INF;
    ll time = 0;
    int id = -1;

    Car() = default;

    Car(int xx, ll t, int i): x(xx), time(t), id(i) {}
};

Car get_best(const Car& a, const Car& b, int x) {
    int d1 = abs(x - a.x);
    int d2 = abs(x - b.x);
    if (d1 != d2)
        return d1 < d2 ? a : b;
    if (a.time != b.time)
        return a.time < b.time ? a : b;
    return a.id < b.id ? a : b;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    map<int, set<pair<ll, int>>> waiting;
    int n, k, m;
    cin >> n >> k >> m;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        waiting[x].insert({0, i});
    }
    ll curt = 0;
    map<ll, vector<pii>> events;
    for (int i = 0; i < m; i++) {
        ll t, a, b;
        cin >> t >> a >> b;
        curt = max(curt, t);
        while (events.size() && events.begin()->first <= curt) {
            auto e = *events.begin();
            events.erase(events.begin());
            for (auto p : e.second) 
                waiting[p.first].insert({e.first, p.second});
        }
        if (waiting.empty()) {
            assert(events.size());
            auto e = *events.begin();
            events.erase(events.begin());
            for (auto p : e.second) 
                waiting[p.first].insert({e.first, p.second});
            curt = e.first;
        }
        assert(waiting.size());
        Car L;
        Car R;
        auto it = waiting.lower_bound(a);
        if (it != waiting.end())
            L = Car(it->first, it->second.begin()->first, it->second.begin()->second);
        if (it != waiting.begin()) {
            --it;
            R = Car(it->first, it->second.begin()->first, it->second.begin()->second);
        }
        Car best = get_best(L, R, a);
        assert (best.id != -1);
        cout << best.id + 1 << " " << curt - t + abs(a - best.x) << "\n";
        waiting[best.x].erase({best.time, best.id});
        if (waiting[best.x].empty())
            waiting.erase(best.x);
        events[curt + abs(a - best.x) + abs(a - b)].push_back({b, best.id});
    }
}