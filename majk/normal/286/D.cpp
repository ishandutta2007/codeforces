#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std; 

#define x first
#define y second

typedef pair<int,int> pii;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);

    int N, M; cin >> N >> M;
    set<int> Open{-2, int(1e9+2)}, Close{-1, int(1e9 + 3)};
    vector<pair<int, pii>> Input, Seg;
    for (int i = 0; i < M; ++i) {
        int l,r,t; cin >> l >> r >> t;
        Input.push_back({t,{l,r}});
    }
    sort(Input.begin(),Input.end());
    
    for (int i = 0; i < M; ++i) {
        int l = Input[i].y.x, r = Input[i].y.y, t = Input[i].x;
        auto op = Open.upper_bound(l);
        auto cl = Close.lower_bound(l);
        if (*op > *cl) { l = *cl; }
        while (l < r) {
            if (l == *cl) Close.erase(cl++); else Open.insert(l);
            if (*op > r) {
                Close.insert(r);
                Seg.push_back({t, {l, r}});
                break;
            } else {
                Seg.push_back({t, {l, *op}});
                Open.erase(op++);
                l = *cl;
            }
        }
    }

    vector<pii> Events;
    for (auto &seg: Seg) {
        int l = seg.y.x, r = seg.y.y, t = seg.x;
        Events.push_back({t-r, 1});
        Events.push_back({t-l, -1});
    }

    for (int i = 0; i < N; ++i) {
        int q; cin >> q;
        Events.push_back({q, 0});
    }
    sort(Events.begin(),Events.end());

    ll cur = 0;
    ll der = 0;
    int prev = -1e9;
    for (auto &ev: Events) {
        cur += (ev.x - prev) * der;
        der += ev.y;
        prev = ev.x;
        if (ev.y == 0) cout << cur << '\n';
    }


}