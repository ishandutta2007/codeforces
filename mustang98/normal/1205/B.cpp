#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

ll a[max_n];
vector<int> vv[max_n];
vector<int> v[max_n];
int p[max_n];
mt19937 gen;

int ans = inf;

int d[max_n];
bool vis[200];

void dfs(int cur, int cd) {
    vis[cur] = 1;
    d[cur] = cd;
    for (int to : v[cur]) {
        if (vis[to] && d[to] < d[cur] - 1) {
            ans = min(ans, d[cur] - d[to] + 1);
        }
        if (!vis[to]) {
            dfs(to, cd + 1);
        }
    }
}

map<int, int> mp;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < 63; ++i) {
        vector<int> id;
        for (int j = 0; j < n; ++j) {
            if (a[j] & (1LL << i)) {
                id.PB(j);
            }
        }
        if (id.size() >= 3) {
            cout << 3 << endl;
            return 0;
        }
        //cout << id.size() << endl;
        if (id.size() == 2) {
            int from = id[0], to = id[1];
            vv[from].PB(to);
            vv[to].PB(from);
            //cout << from  << ' ' << to << endl;
        }
    }
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        if (vv[i].size() == 0) {
            continue;
        }
        mp[i] = cur++;
    }
    for (int i = 0; i < n; ++i) {
        for (int to : vv[i]) {
            int from = mp[i], tt = mp[to];
            v[from].PB(tt);
            v[tt].PB(from);
        }
    }
    n = cur;
    if (n > 200) {
        exit(228);
    }
    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }
    for (int IT = 0; IT < 100000; ++IT) {
        memset(vis, 0, sizeof(vis));
        shuffle(p, p + n, gen);
        for (int i = 0; i < n; ++i) {
            shuffle(v[i].begin(), v[i].end(), gen);
        }
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                dfs(i, 0);
            }
        }
    }
    if (ans == inf) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}