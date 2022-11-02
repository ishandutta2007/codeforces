#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define A first
#define B second

typedef long long ll;
typedef long double ld;

const int maxn = 100100;

int test_case;

int n, m;
vector<int> adj[maxn];
int ans[maxn];
bool vis[maxn];
int stk[maxn], stksze;

pair<ll, ll> dp[maxn];

ll gcd(ll a, ll b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b) {
        ll a1 = b;
        b = a % b;
        a = a1;
    }
    return a;
}

ll lcm(ll a, ll b) { 
    ll g = gcd(a, b);
    if (g == 0) return 0;
    return a / g * b;
}

pair<ll, ll> fix(pair<ll, ll> v) {
    ll g = gcd(v.A, v.B);
    if (g == 0) return MP(0, 0);
    return MP(v.A / g, v.B / g);
}

void print_ans() {
    printf("YES\n");
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    printf("\n");
}

//get lcm of denominators
ll dfs_lcm(int v, int p, pair<ll, ll> l = MP(1, 1)) {
    ll ret = l.B;
    for (int i : adj[v]) {
        if (i == p) continue;
        ret = lcm(ret, dfs_lcm(i, v, fix(MP(l.A * dp[i].B, l.B * 2 * dp[i].A))));
    }
    return ret;
}

void prop_ans(int v, int p, ll l) {
    ans[v] = l;
    for (int i : adj[v]) {
        if (i == p) continue;
        prop_ans(i, v, l * dp[i].B / (2 * dp[i].A));
    }
}

void prop_ans2(int v, int p, ld l) {
    ans[v] = round(l);
    for (int i : adj[v]) {
        if (i == p) continue;
        prop_ans2(i, v, l / dp[i].A * dp[i].B / 2);
    }
}

void tssert(bool b) {
    if (!b) {
        while (1) {}
    }
}

bool dfs_dp(int v, int p = -1) {
    vis[v] = true;
    dp[v] = MP(1, 1);
    for (int i : adj[v]) {
        if (i == p) continue;
        tssert(!vis[i]);
        //if (dfs_dp(i, v)) return true;
        bool b = dfs_dp(i, v);
        if (b) return true;
        //if (71 <= test_case && test_case <= 73) cerr << dp[i].A << ' ' << dp[i].B << endl;
        tssert(dp[i].A > 0 && dp[i].B > 0);
        dp[v] = fix(MP(dp[v].A * 4 * dp[i].A - dp[v].B * dp[i].B, 4 * dp[v].B * dp[i].A));
    }

    if (dp[v].A <= 0 || dp[v].B <= 0) {
        dp[v] = MP(1, 1);
        ll l = dfs_lcm(v, p);
        prop_ans(v, p, l);

        ll g = 0;
        for (int j = 1; j <= n; j++) g = gcd(g, ans[j]);
        for (int j = 1; j <= n; j++) ans[j] /= g;

        int ma = *max_element(ans + 1, ans + n + 1);
            
        int mil = 1000000;
        if (ma > mil) { //do some hacky shit
            ld l2 = ld(ans[v]) / ma * mil;
            prop_ans2(v, p, l2);
        }
        for (int j = 1; j <= n; j++) ans[j] = min(ans[j], mil);

        return true;
    }

    return false;
}

bool go_dp() {
    for (int i = 1; i <= n; i++) vis[i] = false;
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            if (dfs_dp(i)) {
                print_ans();
                return true;
            }
    return false;
}

bool check_deg4() {
    for (int i = 1; i <= n; i++)
        if (adj[i].size() >= 4) {
            ans[i] = 2;
            for (int j = 0; j < 4; j++) ans[adj[i][j]] = 1;
            print_ans();
            return true;
        }
    return false;
}

bool dfs(int v, int p = -1) {
    vis[v] = 1;
    stk[stksze++] = v;
    for (int i : adj[v]) {
        if (i == p) continue;
        if (vis[i]) {
            while (stksze > 0 && stk[stksze - 1] != i) {
                ans[stk[stksze - 1]] = 1;
                stksze--;
            }
            ans[i] = 1;
            return true;
        } else if (dfs(i, v)) return true;
    }
    stksze--;
    return false;
}

bool check_cycles() {
    for (int i = 1; i <= n; i++)
        if (!vis[i]) {
            stksze = 0;
            if (dfs(i)) {
                print_ans();
                return true;
            }
        }
    return false;
}

void init() {
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        ans[i] = 0;
        vis[i] = 0;
        stk[i] = 0;
        dp[i] = MP(0, 0);
    }
    stksze = 0;
}

void go() {
    scanf("%d %d", &n, &m);
    init();

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if (check_deg4()) return;
    if (check_cycles()) return;
    if (!go_dp()) {
        printf("NO\n");
        //for (int i = 1; i <= n; i++) cout << dp[i].A << ' ' << dp[i].B << endl;
    }
}

int main() {
    int t; scanf("%d", &t);
    for (test_case = 1; test_case <= t; test_case++) go();
}