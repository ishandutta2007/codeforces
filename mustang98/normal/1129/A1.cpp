#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 5011, inf = 1000111222;

int n, m;
vector<int> v[max_n];
bool vis[max_n];
int have[max_n];
int nxt[max_n];

int mx = -1;
int cntmax = 0;

int calc(int st) {
    memset(vis, 0, sizeof(vis));
    memset(have, 0, sizeof(have));
    int ans = n * (mx - 1);
    //cout << ans << endl;
    int cvis = 0;
    int chave = 0;

    for (int i = 0; i < n; ++i) {
        int cur = (st + i) % n;
        if (v[cur].size() == mx - 1 && v[cur].size() > 0) {
            have[nxt[cur]]++;
            chave++;
        }
        if (have[cur] > 0) {
            chave -= have[cur];
            have[cur] = 0;
        }
    }
    for (int i = 0;; ++i) {
        int cur = (st + i) % n;
        if (v[cur].size() == mx && !vis[cur]) {
            vis[cur] = 1;
            have[nxt[cur]]++;
            chave++;
            cvis++;
        }
        if (have[cur] > 0) {
            chave -= have[cur];
            have[cur] = 0;
        }
        if (cvis == cntmax && chave == 0) break;
        ++ans;
    }
    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    //n = 5000, m = 20000;
    for (int i = 0; i < m; ++i) {
        int a, b;
        //a = rand() % n;
        //b = rand() % n;
        cin >> a >> b;
        --a, --b;
        v[a].PB(b);
    }
    for (int i = 0; i < n; ++i) {
        mx = max(mx, int(v[i].size()));
        int d = inf;
        for (int j = 0; j < v[i].size(); ++j) {
            int to = v[i][j];
            int cd = to - i;
            if (cd < 0) cd += n;
            if (cd < d) {
                d = cd;
                nxt[i] = to;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (v[i].size() == mx) {
            ++cntmax;
        }
    }
    for (int st = 0; st < n; ++st) {
        cout << calc(st) << ' ';
    }

    return 0;
}