#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 4e5 + 5;
const int K = 14;
const int M = 1e3 + 2;
struct node {
    int nxt[K];
    int go[K];
    int pch;
    int p;
    int link;
    int cost;
};

node a[M];
int used[M], n, c[M], sz = 0;
int to[K + 1][M], cost[K + 1][M], dp[M][(1 << K)];
vector<int> pos;
string s, t[M];

int get_link(int id);
int get_go(int id, int c);

void add_string(string &t, int cost) {
    int cur = 0;
    for (int i = 0; i < t.size(); i++) {
        if (a[cur].nxt[t[i] - 'a'] == -1) {
            sz++;
            a[cur].nxt[t[i] - 'a'] = sz;
            a[sz].p = cur;
            a[sz].pch = t[i] - 'a';
            for (int i = 0; i < K; i++)
                a[sz].go[i] = a[sz].nxt[i] = -1;
            a[sz].cost = 0;
            a[sz].link = -1;
            cur = sz;
        } else
            cur = a[cur].nxt[t[i] - 'a'];
    }
    a[cur].cost += cost;
}

int get_link(int id) {
    if (a[id].link == -1)
        if (id == 0 || a[id].p == 0)
            a[id].link = 0;
        else
            a[id].link = get_go(get_link(a[id].p), a[id].pch);
    return a[id].link;
}

int get_go(int id, int c) {
    if (a[id].go[c] == -1)
        if (a[id].nxt[c] != -1)
            a[id].go[c] = a[id].nxt[c];
        else
            if (id == 0)
                a[id].go[c] = 0;
            else
                a[id].go[c] = get_go(get_link(id), c);
    return a[id].go[c];
}

int get_cost(int id) {
    if (!used[id]) {
        used[id] = 1;
        if (id != 0)
            a[id].cost += get_cost(a[id].link);
    }
    return a[id].cost;
}

void go(int state, int id, string &t) {
    int beg_state = state;
    int sum = 0;
    for (int i = 0; i < t.size(); i++) {
        state = a[state].go[t[i] - 'a'];
        sum += a[state].cost;
    }
    //cout << id << ' ' << beg_state << endl;
    to[id][beg_state] = state;
    cost[id][beg_state] = sum;
}

signed main()
{
    cin >> n;
    a[0].link = 0;
    for (int i = 0; i < K; i++)
        a[0].go[i] = a[0].nxt[i] = -1;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> c[i];
        add_string(t[i], c[i]);
    }
    for (int i = 0; i <= sz; i++)
        get_link(i);
    for (int i = 0; i <= sz; i++)
        for (int c = 0; c < K; c++)
            get_go(i, c);
    for (int i = 0; i <= sz; i++)
        get_cost(i);

    cin >> s;
    pos.pb(-1);
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '?')
            pos.pb(i);
    pos.pb(s.size());
    for (int id = 0; id + 1 < pos.size(); id++) {
        string t = "";
        for (int i = pos[id] + 1; i < pos[id + 1]; i++)
            t += s[i];
        for (int state = 0; state <= sz; state++)
            go(state, id, t);
    }
    for (int i = 0; i <= sz; i++)
        for (int msk = 0; msk < (1 << K); msk++)
            dp[i][msk] = -1e18;
    dp[to[0][0]][0] = cost[0][0];
    for (int msk = 0; msk < (1 << K); msk++)
        for (int state = 0; state <= sz; state++)
            if (dp[state][msk] != -1e18 && __builtin_popcount(msk) < pos.size() - 2) {
                for (int c = 0; c < K; c++)
                    if (!((msk >> c) & 1)){
                        int cur_state = a[state].go[c];
                        int sum = dp[state][msk] + a[cur_state].cost + cost[__builtin_popcount(msk) + 1][cur_state];

                        dp[to[__builtin_popcount(msk) + 1][cur_state]][msk | (1 << c)] = max(dp[to[__builtin_popcount(msk) + 1][cur_state]][msk | (1 << c)], sum);
                    }
            }
    int ans = -1e18;

    for (int msk = 0; msk < (1 << K); msk++)
        for (int state = 0; state <= sz; state++)
            if (__builtin_popcount(msk) == pos.size() - 2)
                ans = max(ans, dp[state][msk]);
    cout << ans;
    return 0;
}