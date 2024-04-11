#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 101, inf = 1000111222;

vector<pair<int, int> > v[4];

bool vis[4];
int com[4];

int cur_c = 0;

void dfs(int cur) {
    vis[cur] = 1;
    com[cur] = cur_c;
    for (int i = 0; i < v[cur].size(); ++i) {
        int to = v[cur][i].F;
        if (!vis[to]) dfs(to);
    }
}

vector<pair<int, int> > e;
vector<int> w;

int solve4() {
    for (int i = 0; i < 4; ++i) {
        vis[i] = 0;
        com[i] = 0;
    }
    cur_c = 0;
    for (int i = 0; i < 4; ++i) {
        if (!vis[i]) {
            dfs(i);
            ++cur_c;
        }
    }
    if (cur_c > 1) {
        int c_w[4] = {0};
        for (int i = 0; i < e.size(); ++i) {
            int a = e[i].F, b = e[i].S;
            c_w[com[a]] += w[i];
        }
        sort(c_w, c_w + 4);
        return c_w[3];
    }
    int ans = 0;
    for (int i = 0; i < w.size(); ++i) {
        ans += w[i];
    }
    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int sumw = 0;
    for (int i = 0; i < n; ++i) {
        int a, b, val;
        cin >> a >> val >> b;
        --a, --b;
        v[a].PB({b, val});
        v[b].PB({a, val});
        e.PB({a, b});
        w.PB(val);
        sumw += val;
    }
    for (int i = 0; i < 4; ++i) {
        if (!vis[i]) {
            dfs(i);
            ++cur_c;
        }
    }
    //cout << cur_c << endl;
    if (cur_c > 1) {
        int c_w[4] = {0};
        for (int i = 0; i < e.size(); ++i) {
            int a = e[i].F, b = e[i].S;
            if (com[a] != com[b]) {
                cout << "AAAAAAA" << endl;
                exit(228);
            }
            c_w[com[a]] += w[i];
        }
        sort(c_w, c_w + 4);
        cout << c_w[3] << endl;
        return 0;
    }

    for (int i = 0; i < 4; ++i) {
        if (v[i].size() % 2 == 0) {
            cout << sumw << endl;
            return 0;
        }
    }
    int ans = 0;
    for (int i = 0; i < e.size(); ++i) {
        int a = e[i].F, b = e[i].S;
        if (a == b) continue;
        for (int j = 0; j < v[a].size(); ++j) {
            int to = v[a][j].F;
            if (to == b) {
                v[a].erase(v[a].begin() + j);
                break;
            }
        }
        for (int j = 0; j < v[b].size(); ++j) {
            int to = v[b][j].F;
            if (to == a) {
                v[b].erase(v[b].begin() + j);
                break;
            }
        }
        int cur_w = w[i];
        w[i] = 0;
        ans = max(ans, solve4());
        w[i] = cur_w;
        v[a].PB({b, w[i]});
        v[b].PB({a, w[i]});
    }
    cout << ans << endl;
    return 0;
}