#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;
using ll = long long;

static constexpr int BLOCK = 500;

struct Event {
    int l;
    int r;
    int id;

    bool operator<(const Event& e) const {
        return r < e.r;
    }
};

class State {
    vector<ll> cnt_start;
    vector<ll> cnt_end;
    vector<int> time_start;
    vector<int> time_end;
    int timer = 1;
    ll ans = 0;

    int get_start(int pos) const {
        if (time_start[pos] != timer) 
            return 0;
        return cnt_start[pos];
    }

    int get_end(int pos) const {
        if (time_end[pos] != timer)
            return 0;
        return cnt_end[pos];
    }

    void set_start(int pos, ll val) {
        time_start[pos] = timer;
        cnt_start[pos] = val;
    }

    void set_end(int pos, ll val) {
        time_end[pos] = timer;
        cnt_end[pos] = val;
    }

public:
    State(int n): cnt_start(2 * n), cnt_end(2 * n), time_start(2 * n), time_end(2 * n) {}

    void add_to_left(int st, int en) {
        ans += get_start(en);
        set_start(st, get_start(st) + 1);
        set_end(en, get_end(en) + 1);
    }

    void remove_from_left(int st, int en) {
        set_start(st, get_start(st) - 1);
        set_end(en, get_end(en) - 1);
        ans -= get_start(en);
    }

    void add_to_right(int st, int en) {
        ans += get_end(st);
        set_start(st, get_start(st) + 1);
        set_end(en, get_end(en) + 1);
    }

    void clear() {
        ans = 0;
        ++timer;
    }

    ll get_ans() const {
        return ans;
    }
};

ll solve_small(const vector<int>& starts, const vector<int>& ends, int l, int r, State& state) {
    state.clear();
    for (int i = l - 1; i <= r; i++)
        state.add_to_right(starts[i], ends[i]);
    return state.get_ans();
}

vector<ll> solve(const vector<int>& starts, const vector<int>& ends, const vector<pii>& qs) {
    int n = starts.size();
    int m = qs.size();
    vector<ll> ans(qs.size());
    vector<vector<Event>> ev((n + BLOCK - 1) / BLOCK);
    State state(2 * n);
    for (int i = 0; i < m; i++) {
        auto q = qs[i];
        int bl = q.first / BLOCK;
        int br = q.second / BLOCK;
        if (bl < br)
            ev[bl].push_back({q.first, q.second, i});
        else
            ans[i] = solve_small(starts, ends, q.first, q.second, state);
    }
    for (int b = 0; b < (int)ev.size(); b++) {
        state.clear();
        int next_block = (b + 1) * BLOCK;
        sort(ev[b].begin(), ev[b].end());
        int cur_r = next_block;
        for (const auto& e : ev[b]) {
            while (cur_r <= e.r) {
                state.add_to_right(starts[cur_r], ends[cur_r]);
                ++cur_r;
            }
            ll old_ans = state.get_ans();
            for (int i = next_block - 1; i >= e.l - 1; i--)
                state.add_to_left(starts[i], ends[i]);
            ans[e.id] = state.get_ans();
            for (int i = e.l - 1; i < next_block; i++)
                state.remove_from_left(starts[i], ends[i]);
            assert(state.get_ans() == old_ans);
        }
    }
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    ll k;
    cin >> n >> k;
    vector<int> t(n);
    for (int& x : t)
        cin >> x;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (t[i - 1] == 2)
            a[i] = -a[i];
        a[i] += a[i - 1];
    }

    vector<ll> all(a.begin(), a.end());
    for (ll x : a)
        all.push_back(x - k);
    sort(all.begin(), all.end());
    all.resize(unique(all.begin(), all.end()) - all.begin());
    vector<int> starts(n + 1);
    vector<int> ends(n + 1);
    for (int i = 0; i < n + 1; i++) {
        starts[i] = lower_bound(all.begin(), all.end(), a[i] - k) - all.begin();
        ends[i] = lower_bound(all.begin(), all.end(), a[i]) - all.begin();
    }

    int q;
    cin >> q;
    vector<pii> lr(q);
    for (auto& p : lr) 
        cin >> p.first >> p.second;
    for (ll ans : solve(starts, ends, lr))
        cout << ans << "\n";
}