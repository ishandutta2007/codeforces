#include <bits/stdc++.h>
using namespace std;
int n;
const int maxN = 1005;
vector < int > ne;
vector < int > v;
int a[maxN];
bool ok[maxN];
vector < pair < int, int > > sol;
int pos[maxN];
bool dfs(vector < int > v, int k) {
    bool rok = true;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] != a[i + 1]) {rok = false; break;}
    }
    //cout << "HERE      " << k << endl;
    if (rok) {
        return true;
    }
    if (k == 3) return false;
    vector < int > ne;
    for (int i = 0; i < n; i++) {
        if (ok[v[i]]) ne.push_back(i + 1);
    }
    for (int i = 0; i < ne.size(); i++) {
        for (int j = i + 1; j < ne.size(); j++) {
            int l = ne[i] - 1, r = ne[j] - 1;
            vector < int > w = v;
            for (int p = l; p <= (l + r) / 2; p++) {
                swap(w[p], w[l + r - p]);
            }
            if (dfs(w, k + 1)) {
                //cout << k << " ";
                sol.push_back(make_pair(l + 1, r + 1));
                return true;
            }
        }
    }
    return false;
}
int main() {
    //freopen("hentium.in", "r", stdin);
    //freopen("hentium.out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    srand(time(0));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    for (int i = 1; i <= n - 1; i++) {
        if (abs(a[i] - a[i + 1]) != 1) ok[a[i]] = ok[a[i + 1]] = true;
    }
    ok[a[1]] = true;
    ok[a[n]] = true;
    a[n + 1] = n + 1;
    for (int i = 1; i <= n; i++) {
        if (ok[i]) ne.push_back(i);
    }
    for (int i = 1; i <= n; i++) v.push_back(i);
    dfs(v, 0);
    cout << sol.size() << '\n';
    reverse(sol.begin(), sol.end());
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i].first << " " << sol[i].second << '\n';
    }
    return 0;
}