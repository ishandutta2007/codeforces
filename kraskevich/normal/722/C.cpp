#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 100 * 1000 + 10;
int n;
ll a[N];
int p[N];
ll ans[N];
ll tot_best = 0;

struct Segm {
    int l;
    int r;
    ll best;
    ll sum;
    ll tmax;
    ll tmin;

    Segm(int l, int r, ll best = 0, ll sum = 0, ll tmax = 0, ll tmin = 0):
            l(l), r(r), best(best), sum(sum), tmax(tmax), tmin(tmin) {
        tot_best = max(tot_best, best);
    }

    Segm unite(const Segm& s) const {
        Segm res(l, s.r);
        res.best = max(best, s.best);
        res.best = max(res.best, sum + s.tmax - tmin);
        res.tmax = max(tmax, s.tmax + sum);
        res.tmin = min(tmin, s.tmin + sum);
        res.sum = sum + s.sum;
        tot_best = max(tot_best, res.best);
        return res;
    }

    bool operator<(const Segm& s) const { 
        return l < s.l;
    }
};

set<Segm> q;

void put(int pos, ll val) {
    auto it = q.lower_bound(Segm(pos, pos));
    auto was = it;
    bool del = false;
    Segm cur = Segm(pos, pos, max(0ll, val), val, max(0ll, val), min(0ll, val));
    if (it != q.end() && it->l == pos + 1) {
        cur = cur.unite(*it);  
        del = true;      
    }
    if (it != q.begin()) {
        it--;
        if (it->r == pos - 1) {
            cur = it->unite(cur);
            q.erase(it);
        }
    }
    if (del) {
        q.erase(was);
    }
    q.insert(cur); 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++) {   
        cin >> p[i];
        p[i]--;
    }
    for (int i = n - 1; i >= 0; i--) {
        ans[i] = tot_best;
        put(p[i], a[p[i]]);
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << "\n";    
    return 0;
}