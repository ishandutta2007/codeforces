#include <bits/stdc++.h>
using namespace std;
const int maxN = 2505;
int n;
int a[maxN][maxN];
vector < int > ans;
void no() {
    cout << "NOT MAGIC";
    exit(0);
}
void solve(vector < int > v, int upper) {
    if (v.size() <= 1) return ;
    vector < pair < int, int > > edges;
    for (int i = 1; i < v.size(); i++) {
        edges.push_back(make_pair(a[v[0]][v[i]], v[i]));
    }
    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());
    vector < int > redges;
    for (int i = 0; i < edges.size(); i++) {
        redges.push_back(edges[edges.size() - 1 - i].second);
    }
    int prv = -1;
    vector < int > g;
    for (int i = 0; i < edges.size(); i++) {
        int val = edges[i].first;
        if (val > upper) no();
        if (prv != val && prv != -1) {
            solve(g, prv);
            for (int j = 0; j < g.size(); j++) {
                for (int k = 0; k < redges.size(); k++) {
                    //cout << g[j] << " " << redges[k] << '\n';
                    if (a[g[j]][redges[k]] != prv) no();
                }
            }
            g.clear();
            prv = val;
            g.push_back(edges[i].second);
            redges.pop_back();
        }
        else {
            prv = val;
            g.push_back(edges[i].second);
            redges.pop_back();
        }
    }
    solve(g, prv);
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (i == j) {
                if (a[i][j] != 0) no();
            }
            if (i > j) {
                if (a[i][j] != a[j][i]) no();
            }
        }
    }
    for (int i = 1; i <= n; i++) ans.push_back(i);
    solve(ans, (int)1e9 + 5);
    cout << "MAGIC";
    return 0;
}