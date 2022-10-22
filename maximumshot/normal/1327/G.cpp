#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int A = 14; // alphabet size
struct Aho {

    struct Node {
        int nxt[A], go[A];
        int par, pch, link;
        int len;
        ll sum;

        Node():
                par(-1), pch(-1), link(-1), len(0), sum(0)
        {
            fill(nxt, nxt + A, -1);
            fill(go, go + A, -1);
        }
    };

    vector<Node> a;

    Aho() {
        a.emplace_back();
    }

    void add_string(const string &s, ll cost) {
        int v = 0;
        for(char c : s) {
            if(a[v].nxt[c] == -1) {
                a[v].nxt[c] = (int)a.size();
                a.emplace_back();
                a.back().par = v;
                a.back().pch = c;
                a.back().len = a[v].len + 1;
            }
            v = a[v].nxt[c];
        }
        a[v].sum += cost;
    }

    int go(int v, int c) {
        if(a[v].go[c] == -1) {
            if(a[v].nxt[c] != -1) {
                a[v].go[c] = a[v].nxt[c];
            }else {
                a[v].go[c] = v ? go(get_link(v), c) : 0;
            }
        }
        return a[v].go[c];
    }

    int get_link(int v) {
        if(a[v].link == -1) {
            if(!v || !a[v].par) a[v].link = 0;
            else a[v].link = go(get_link(a[v].par), a[v].pch);
        }
        return a[v].link;
    }

    void push_sum() {
        vector<int> vs(a.size());
        for (int i = 0; i < (int) vs.size(); i++)
            vs[i] = i;
        sort(vs.begin(), vs.end(), [&](int v1, int v2){
            return a[v1].len < a[v2].len;
        });
        for (int v : vs) {
            a[v].sum += a[get_link(v)].sum;
        }
    }
};

inline void upd(ll &x, ll y) {
    if (x < y)
        x = y;
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;
    vector<string> t(k);
    vector<ll> cost(k);
    Aho aho;
    for (int i = 0; i < k; i++) {
        cin >> t[i] >> cost[i];
        for (char &c : t[i])
            c -= 'a';
        aho.add_string(t[i], cost[i]);
    }
    aho.push_sum();

    string s;
    cin >> s;

    vector<int> ps = {-1};
    for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] == '?')
            ps.push_back(i);
        else
            s[i] -= 'a';
    }
    ps.push_back((int) s.size());

//    s = "abcdefghijklmn";
//    for (char &c : s)
//        c -= 'a';
//    {
//        ll res = 0;
//        for (int v = 0, i = 0; i < (int) s.size(); i++) {
//            char c = s[i];
//            v = aho.go(v, c);
//            res += aho.a[v].sum;
//        };
//        cout << res << "\n";
//    }

    int sz = (int) aho.a.size();
    vector<vector<pair<int, ll>>> mem(sz, vector<pair<int, ll>>(ps.size()));

    for (int i = 0; i + 1 < (int) ps.size(); i++) {
        int fr = ps[i] + 1;
        int to = ps[i + 1] - 1;
        for (int start = 0; start < sz; start++) {
            ll cur_sum = 0;
            int v = start;
            for (int p = fr; p <= to; p++) {
                v = aho.go(v, s[p]);
                cur_sum += aho.a[v].sum;
            }
            mem[start][i] = {v, cur_sum};
        }
    }

    // dp[question_pos][vertex][mask]
    // 14 * 1000 * 2^14

    vector<vector<ll>> dp(sz, vector<ll>(1 << 14, -inf64)), nx;

    dp[0][0] = 0;

    vector<int> cnt_bit(1 << 14);
    for (int i = 0; i < (int) cnt_bit.size(); i++) {
        cnt_bit[i] = __builtin_popcount(i);
    }

    for (int i = 0; i + 2 < (int) ps.size(); i++) {
        nx.assign(sz, vector<ll>(1 << 14, -inf64));
        for (int v = 0; v < sz; v++) {
            int nxt;
            ll score;
            tie(nxt, score) = mem[v][i];
            for (int mask = 0; mask < (1 << 14); mask++) {
                if (cnt_bit[mask] != i)
                    continue;
                for (int c = 0; c < 14; c++) {
                    if (((1 << c) & mask))
                        continue;
                    int nxt_mask = mask | (1 << c);
                    int to = aho.go(nxt, c);
                    ll tmp = score + aho.a[to].sum;
                    upd(nx[to][nxt_mask], dp[v][mask] + tmp);
                }
            }
        }
        dp = nx;
    }

    int cnt_q = (int) ps.size() - 2;
    ll res = -inf64;
    for (int mask = 0; mask < (1 << 14); mask++) {
        if (cnt_bit[mask] != cnt_q)
            continue;
        for (int v = 0; v < sz; v++) {
            int nxt;
            ll score;
            tie(nxt, score) = mem[v][(int) ps.size() - 2];
            upd(res, dp[v][mask] + score);
        }
    }

    cout << res << "\n";

    return 0;
}