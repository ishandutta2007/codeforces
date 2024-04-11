#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;

const int root = 646;

const int root_1 = 208611436;

const int root_pw = 1<<20;

int mult(int a, int b) {
    return (1LL * a * b) % mod;
}

int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}

int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}

int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}

const int K = 14;
struct vertex {
    int next[K];
    bool leaf;
    int p;
    char pch;
    int link;
    ll cost;
    int go[K];
    ll tot_val;
};

const int NMAX = 3e5;

vertex t[NMAX+1];
int sz;


const ll INF = 1e18;

void init() {
    t[0].p = t[0].link = -1;
    t[0].tot_val = -INF;
    memset (t[0].next, 255, sizeof t[0].next);
    memset (t[0].go, 255, sizeof t[0].go);
    sz = 1;
}

void add_string (const string & s, int c) {
    int v = 0;
    for (size_t i=0; i<s.length(); ++i) {
        char c = s[i]-'a';
        if (t[v].next[c] == -1) {
            memset (t[sz].next, 255, sizeof t[sz].next);
            memset (t[sz].go, 255, sizeof t[sz].go);
            t[sz].link = -1;
            t[sz].tot_val = -INF;
            t[sz].p = v;
            t[sz].pch = c;
            t[v].next[c] = sz++;
        }
        v = t[v].next[c];
    }
    t[v].leaf = true;
    t[v].cost += c;
}

int go (int v, char c);

int get_link (int v) {
    if (t[v].link == -1)
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go (get_link (t[v].p), t[v].pch);
    return t[v].link;
}

int go (int v, char c) {
    if (t[v].go[c] == -1)
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v==0 ? 0 : go (get_link (v), c);
    return t[v].go[c];
}

ll calc(int v) {
    if (v == -1 || v == 0) return 0;
    if (t[v].tot_val != -INF) {
        return t[v].tot_val;
    }
    else {
        t[v].tot_val = calc(get_link(v)) + t[v].cost;
        return t[v].tot_val;
    }
}

int k;
string tt[1005];
int c[1005];
string s;
int p[1005];
int FROM;
int TO;
map < pair < int, int >, pair < int, ll > > mp;
pair < int, ll > go(int state, int from, int to) {
    int ws = state;
    if (mp.find({state, from}) != mp.end()) return mp[{state, from}];
    if (from > to) return {state, 0};
    state = go(state, s[from] - 'a');
    ll ans = calc(state);
    auto pp = go(state, from + 1, to);
    mp[{ws, from}] = make_pair(pp.first, ans + pp.second);
    return make_pair(pp.first, ans + pp.second);
}
vector < pair < int, ll > > calc_trans(int from, int to) {
    mp.clear();
    vector < pair < int, ll > > all(sz + 1);
    for (int i = 0; i <= sz; i++) {
        all[i] = go(i, from, to);
    }
    return all;
}
vector < int > by_bit[15];
void upd(ll& a, ll b) {
    a = max(a, b);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    init();
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> tt[i] >> c[i];
        add_string(tt[i], c[i]);
    }
    vector < int > que;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '?') {
            que.emplace_back(i);
        }
    }
    vector < vector < ll > > dp((1 << 14) + 2, vector < ll >(sz + 1, -INF));
    for (int i = 0; i < (1 << 14); i++) {
        int c = 0;
        for (int j = 0; j < 14; j++) {
            if (i & (1 << j)) c++;
        }
        by_bit[c].emplace_back(i);
    }
    dp[0][0] = 0;
    ll ans = -INF;

    for (int i = 0; i <= que.size(); i++) {
        int l, r;
        if (i == 0) {
            l = 0;
            r = (que.empty() ? s.size() - 1 : que[0] - 1);
        }
        else if (i == que.size()) {
            l = que.back() + 1;
            r = s.size() - 1;
        }
        else {
            l = que[i - 1] + 1;
            r = que[i] - 1;
        }

        auto it = calc_trans(l, r);

        for (int mask : by_bit[i]) {
            for (int j = 0; j <= sz; j++) {
                if (dp[mask][j] < -1e17) continue;
                int nj = it[j].first;
                ll to_add = it[j].second;
                if (i != que.size()) {
                    for (int symb = 0; symb < 14; symb++) {
                        if (mask & (1 << symb)) continue;
                        upd(dp[mask | (1 << symb)][go(nj, symb)], dp[mask][j] + to_add + calc(go(nj, symb)));
                    }
                }
                else {
                    ans = max(ans, dp[mask][j] + to_add);
                }
            }
        }
    }
    cout << ans;
    return 0;
}