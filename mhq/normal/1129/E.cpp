#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int ask(vector < int > S, vector < int > T, int v) {
    //cout << "----------------------" << endl;
    cout << S.size() << endl;
    for (int v : S) cout << v << " ";
    cout << endl;
    cout << T.size() << endl;
    for (int v : T) cout << v << " ";
    cout << endl;
    cout << v << endl;
  //  cout << "---------------------------" << endl;
    int ans;
    cin >> ans;
    return ans;
}
bool between(int u, int v, int w) {
    return ask(vector < int >(1, u), vector < int >(1, v), w) > 0;
}
const int maxN = 505;
int sz[maxN];
vector < pair < int, int > > ed;
mt19937 rnd(228);
int curRoot = -1;
void go(int l, int r, vector < int >& cur, int root, int cnt, vector < int >& inside, vector < int >& outside) {
    if (cnt == r - l + 1) {
        for (int i = l; i <= r; i++) {
            inside.push_back(cur[i]);
        }
        return;
    }
    if (cnt == 0) {
        for (int i = l; i <= r; i++) {
            outside.push_back(cur[i]);
        }
        return ;
    }
    int m = (l + r) / 2;
    vector < int > x;
    for (int i = l; i <= m; i++) {
        x.push_back(cur[i]);
       // cout << cur[i] << " gg" << endl;
    }
    int le = ask(x, {curRoot}, root);
    go(l, m, cur, root, le, inside, outside);
    go(m + 1, r, cur, root, cnt - le, inside, outside);
}
void solve(int root, vector < int > all) {
    if (all.empty()) return ;
    curRoot = root;
    int best = all[0];
    for (int v : all) {
        if (sz[best] < sz[v]) best = v;
    }
    ed.emplace_back(root, best);
    vector < int > cur;
    for (int v : all) {
        if (v == best) continue;
        cur.push_back(v);
    }
    //shuffle(cur.begin(), cur.end(), rnd);
    vector < int > inside, outside;
    go(0, (int)cur.size() - 1, cur, best, sz[best] - 1, inside, outside);
    solve(best, inside);
    solve(root, outside);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector < int > all;
    for (int i = 2; i <= n; i++) all.push_back(i);
    for (int i = 2; i <= n; i++) {
        sz[i] = ask({1}, all, i);
    }
    solve(1, all);
    cout << "ANSWER" << endl;
    for (auto t : ed) {
        cout << t.first << " " << t.second << endl;
    }
};