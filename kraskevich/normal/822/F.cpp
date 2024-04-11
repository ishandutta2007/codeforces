#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 111;

vector<int> g[N];
vector<pii> ans;
vector<double> ans_x;

void dfs(int v, int par, double t0) {
    double step = 2. / g[v].size();
    double cur = t0;
    for (int to : g[v]) {
        if (to == par)
            continue;
        cur += step;
        cur = fmod(cur, 2);
        if (cur <= 1.0) {      
            ans.push_back({to, v});
            ans_x.push_back(1. - cur);
            dfs(to, v, cur + 1);
        } else {
            ans.push_back({v, to});
            ans_x.push_back(2 - cur);
            dfs(to, v, cur - 1);
        }
    }
}

map<pii, int> idx;

pii make_edge(int a, int b) {
    if (a > b)
        swap(a, b);
    return pii(a, b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
        idx[make_edge(a, b)] = i;
    }
    dfs(0, 0, 0.0);
    cout << n - 1 << "\n";
    cout.setf(ios::fixed);
    cout.precision(12);
    for (int i = 0; i < n - 1; i++) 
        cout << 1 << " " << idx[make_edge(ans[i].first, ans[i].second)] + 1 << " " << ans[i].first + 1 << " " << ans[i].second + 1 << " " << ans_x[i] << "\n";
}