#include <bits/stdc++.h>
using namespace std;
int k, n, m;
vector < pair < int, pair < int, int > > > g[(int)1e5 + 10];
int cnt = 0;
int st[(int)1e5 + 10];
int curmx[(int)1e5 + 10];
int idx[(int)1e5 + 10];
pair < double, pair < int, int > > ans[(int)1e5 + 10];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> k >> n >> m;
    for (int i = 1; i <= k; i++) cin >> st[i];
    for (int i = 1; i <= n; i++) {
        int ty, id, b;
        cin >> ty >> id >> b;
        if (ty == 1) {
            if (b > st[id] && b > curmx[id]) {
                curmx[id] = b;
                idx[id] = i;
            }
        }
        if (ty == 2) {
            g[id].push_back(make_pair(b, make_pair(i, 2)));
        }
        if (ty == 3) {
            ans[cnt] = make_pair(b * 1.0, make_pair(i, 3));
            cnt++;
        }
    }
    for (int i = 1; i <= k; i++) {
        if (curmx[i] > 0) {
            g[i].push_back(make_pair(curmx[i] - st[i], make_pair(idx[i], 1)));
        }
    }
    for (int i = 1; i <= k; i++) {
        if (g[i].size() == 0) continue;
        double sum = st[i];
        sort(g[i].begin(), g[i].end());
        reverse(g[i].begin(), g[i].end());
        for (int j = 0; j < g[i].size(); j++) {
            ans[cnt] = make_pair((sum + g[i][j].first) / (sum), make_pair(g[i][j].second.first, g[i][j].second.second));
            sum += g[i][j].first;
            cnt++;
        }
    }
    sort(ans, ans + cnt);
    reverse(ans, ans + cnt);
    cout << min(m, cnt) << '\n';
    vector < pair < int, int > > an;
    for (int i = 0; i < min(cnt, m); i++) {
        an.push_back(make_pair(ans[i].second.second, ans[i].second.first));
    }
    sort(an.begin(), an.end());
    for (int i = 0; i < an.size(); i++) {
        cout << an[i].second << " ";
    }
    return 0;
}