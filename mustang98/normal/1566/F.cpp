#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111;
ll inf = 10001112223LL;

int n, m;
vector<ll> p;
vector<pair<ll, ll>> seg;
bool rem_s[max_n];
ll dp[max_n][2];

void clr(int n, int m) {
    for (int i = 0; i < m; ++i) {
        rem_s[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        dp[i][0] = dp[i][1] = inf;
    }
    p.clear();
    seg.clear();
}

bool debug = 1;

void solve() {
    cin >> n >> m;
    clr(n, m);
    vector<pair<pair<ll, char>, ll>> ev;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        p.push_back(x);
        ev.emplace_back(MP(x, 'd'), i);
    }
    for (ll i = 0; i < m; ++i) {
        ll l, r;
        cin >> l >> r;
        seg.emplace_back(l, r);
        ev.emplace_back(MP(l, 'b'), i);
        ev.emplace_back(MP(r, 'e'), i);
    }
    m = seg.size();
    sort(ev.begin(), ev.end());
    set<pair<ll, ll>> s;
    for (auto p : ev) {
        //cout << p.F.F << ' ' << p.F.S << ' ' << p.S << endl;
        ll ind = p.S;
        //cout << "ENTER" << endl;
        if (p.F.S == 'b') {
            //cout << "1 " << endl;
            s.emplace(seg[ind].F, ind);
        } else if (p.F.S == 'd') {
            //cout << "2 " << endl;
            while(!s.empty()) {
                rem_s[s.begin()->S] = true;
                s.erase(s.begin());
            }
        } else {
            //cout << "3 " << endl;
            ll l = seg[ind].F;
            while(!s.empty() && s.begin()->F <= l) {
                if (s.begin()->S != ind) rem_s[s.begin()->S] = true;
                s.erase(s.begin());
            }
            auto it = s.find(MP(seg[ind].F, ind));
            if (it != s.end()) {
                s.erase(it);
            }
        }
        //cout << "QUIT" << endl;
    }
    //cout << "QQ" << endl;
    vector<pair<ll, ll>> seg2;
    for (int i = 0; i < m; ++i) {
        if (rem_s[i]) {
            continue;
        }
        seg2.PB(seg[i]);
    }
    seg.swap(seg2);
    seg2.clear();
    m = seg.size();
    if (seg.size() == 0) {
        cout << 0 << "\n";
        return;
    }
    if (0 && debug) {
        for (int x : p) {
            cout << x << ' ';
        }
        cout << endl;
        for (pair<int, int> p : seg) {
            cout << p.F << ' ' << p.S << endl;
        }
        cout << endl;
        exit(1);
    }


    sort(seg.begin(), seg.end());
    sort(p.begin(), p.end());
    p.push_back(5000000000LL);
    for (int i = 0; i < p.size(); ++i) {
        ll x = p[i];
        int ind = lower_bound(seg.begin(), seg.end(), MP(x, -inf)) - seg.begin();
        if (ind == 0) {
            dp[i][0] = dp[i][1] = 0;
            continue;
        }
        --ind;
        if (i == 0) {
            dp[i][0] = x - seg[0].S;
            dp[i][1] = dp[i][0] * 2;
            continue;
        }
        ll px = p[i - 1];
        int from = ind;
        int cnt = 0;
        for (int i = from; i >= 0; --i) {
            if (seg[i].F < px) {
                break;
            }
            ++cnt;
        }
        //cout << "%% " << from << ' ' << cnt << endl;
        if (cnt == 0) {
            dp[i][0] = dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);
            continue;
        }
        dp[i][0] = dp[i][1] = inf;
        {
            ll prev_way = seg[from].F - px;
            ll prev = min(dp[i - 1][0] + 2 * prev_way, dp[i - 1][1] + prev_way);
            dp[i][0] = dp[i][1] = prev;
        }
        //cout << "$ " << dp[i][0] << ' ' << dp[i][1] << endl;

        for (int j = 0; j < cnt; ++j) {
            ll cur_way = x - seg[from - j].S;
            ll prev = min(dp[i - 1][0], dp[i - 1][1]);
            if (j + 1 != cnt) {
                ll prev_way = seg[from - j - 1].F - px;
                prev = min(dp[i - 1][0] + 2 * prev_way, dp[i - 1][1] + prev_way);
            }
            //cout << "%%% " << cur_way << ' ' << prev << endl;
            dp[i][0] = min(dp[i][0], prev + cur_way);
            dp[i][1] = min(dp[i][1], prev + cur_way * 2);
        }
    }
    n = p.size() - 1;
    /*for (int i = 0; i <= n; ++i) {
        cout << p[i] << ": " << dp[i][0] << ' ' << dp[i][1] << endl;
    }*/
    cout << min(dp[n][0], dp[n][1]) << "\n";
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    while(T--) {
        //clr();
        solve();
    }
    return 0;
}