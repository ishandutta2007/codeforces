#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define pi pair<int, int>

using namespace std;

const int N = (1 << 20) + 1;
const int MM = 20;///change to 20

int ans = 0;
int n, a[N], cur[N], kol[N], used[N];
vector<int> g[N];
vector<pair<int, int> > e;
vector<int> res;

bool tr(int ans) {
    int total = 0;
    for (int i = 0; i < (1 << ans); i++)
        g[i].clear();
    res.clear();
    e.clear();
    for (int i = 1; i <= n + n; i += 2) {
        int x = a[i] % (1 << ans);
        int y = a[i + 1] % (1 << ans);
        g[x].pb(e.size());
        g[y].pb(e.size());
        used[e.size()] = 0;
        e.pb({x, y});
        cur[x] = 0;
        cur[y] = 0;
    }

    ///find euler cycle
    int first = 0;
    while (g[first].size() == 0)
        first++;
    stack<int> st;
    st.push(first);
    while (!st.empty()) {
        int v = st.top();
        for (; cur[v] < g[v].size(); cur[v]++)
            if (!used[g[v][cur[v]]]) {
                break;
            }
        if (cur[v] == g[v].size()) {
            res.pb(v);
            st.pop();
        } else {
            int i = cur[v];
            used[g[v][i]] = 1;
            if (e[g[v][i]].first == v)
                st.push(e[g[v][i]].second);
            else
                st.push(e[g[v][i]].first);
        }
    }
    if (res.size() == n + 1)
        return 1;
    return 0;
}

//map<pair<int, int>, vector<pair<int, int>> > q;
int val[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n + n; i++)
        cin >> a[i];
    for (int k = 1; k <= MM; k++) {
        for (int i = 0; i < (1 << k); i++)
            kol[i] = 0;
        for (int i = 1; i <= n + n; i++) {
            int x = a[i] % (1 << k);
            kol[x]++;
        }
        int can = 1;
        for (int i = 0; i < (1 << k); i++)
            if (kol[i] % 2 == 1) {
                can = 0;
                break;
            }
        if (can && tr(k)) {
            ans = k;
        }
        //cout << k << endl;
    }
    cout << ans << "\n";
    //return 0;
    tr(ans);

    set<pair<pair<int, int>, int> > q;
    for (int i = 1; i <= n + n; i += 2) {
        int x = a[i] % (1 << ans);
        int y = a[i + 1] % (1 << ans);
        val[i] = x;
        val[i + 1] = y;
        q.insert({{x, y}, i});
    }
    for (int i = 0; i + 1 < res.size(); i++) {
        int v = res[i], u = res[i + 1];
        auto it = q.lower_bound({{v, u}, -1});
        if (it == q.end() || it -> first.first != v || it -> first.second != u) {
            it = q.lower_bound({{u, v}, - 1});
            cout << it->second + 1 << ' ' << it -> second << ' ';
            q.erase(it);
        } else {
            cout << it -> second << ' ' << it -> second + 1 << ' ';
            q.erase(it);
        }
    }
    return 0;
}