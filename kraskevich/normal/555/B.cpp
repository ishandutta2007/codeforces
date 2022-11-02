#include <bits/stdc++.h>

using namespace std;

struct Event {
    long long x;
    long long l;
    int id;
    int type; // 0 - point 1 - right 
    
    Event(long long x, long long l, int id, int type): x(x), l(l), id(id), type(type) {}

    bool operator<(const Event& e) const {
        if (x != e.x)
            return x < e.x;
        return type < e.type;
    }
};
 
typedef pair<long long, long long> pll;

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;  
    vector<Event> e;
    vector<long long> l(n);
    vector<long long> r(n);
    vector<int> ans(n - 1);
    for (int i = 0; i < n; i++)
        cin >> l[i] >> r[i];
    for (int i = 1; i < n; i++) {
        long long high = r[i] - l[i - 1];
        long long low = l[i] - r[i - 1];
        e.push_back(Event(high, low, i - 1, 1));
    }
    for (int i = 0; i < m; i++) {
        long long a;
        cin >> a;
        e.push_back(Event(a, a, i + 1, 0));
    }
    sort(e.begin(), e.end());
    multiset<pll> q;
    for (auto ev : e)
        if (ev.type == 0) 
            q.insert(pll(ev.x, ev.id));
        else {
            pll cur = pll(ev.l, 0);
            auto it = q.lower_bound(cur);
            if (it == q.end()) {
                cout << "No\n";
                return 0;
            } 
            ans[ev.id] = it->second;
            q.erase(it);
        }
    cout << "Yes\n";
    for (int i = 0; i < n - 1; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}