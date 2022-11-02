#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const ll INF = (ll)1e18;

struct Event {
    ll x;
    ll len;
    ll cost;
    int type; // 1 - check -1 - delete

    Event(ll xx, ll l, ll cc, int tt): x(xx), len(l), cost(cc), type(tt) {}

    bool operator<(const Event& e) const {
        if (x != e.x)
            return x < e.x;
        return type < e.type;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    map<ll, multiset<ll>> q;
    ll ans = INF;
    int n;
    cin >> n;
    ll x;
    cin >> x;
    vector<Event> es;
    for (int i = 0; i < n; i++) {
        ll l, r, c;
        cin >> l >> r >> c;
        q[r - l + 1].insert(c);
        es.push_back(Event(l, r - l + 1, c, -1));
        es.push_back(Event(r, r - l + 1, c, 1));
    }
    sort(es.begin(), es.end());
    for (auto e : es)
        if (e.type == 1) {
            if (q.count(x - e.len) && !q[x - e.len].empty())
                ans = min(ans, e.cost + *q[x - e.len].begin());
        } else {
            q[e.len].erase(q[e.len].find(e.cost));
        }
    if (ans == INF)
        ans = -1;
    cout << ans << "\n";
}