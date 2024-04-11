#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 605;
int n;
int queries = 0;
map < vector < int >, int > asked;
int ask(vector < int > t) {
    sort(t.begin(), t.end());
    if (asked[t] > 0) return asked[t] - 1;
    if (t.size() <= 1) return 0;
    queries++;
    assert(queries <= 2 * (int)1e4);
    cout << "? " << t.size() << endl;
    for (int v : t) {
        cout << v << " ";
    }
    cout << endl;
    int ans;
    cin >> ans;
    asked[t] = ans + 1;
    return ans;
}
int num_edge(vector < int > a, vector < int > b) {
    if (a.size() == 1 && b.size() == 1) {
        vector<int> v;
        v.push_back(a[0]);
        v.push_back(b[0]);
        return ask(v);
    }
    int x = ask(a);
    int y = ask(b);
    for (int v : b) a.push_back(v);
    int sum = ask(a);
    return sum - x - y;
}
pair < int, int > find_edge(vector < int > a, vector < int > b) {
    if (a.size() > b.size() && b.size() == 1) swap(a, b);
    if (a.size() == 1 && b.size() == 1) return make_pair(a[0], b[0]);
    int l = 0;
    int r = b.size() - 1;
    vector < int > single;
    single.push_back(b[0]);
    if (num_edge(a, single) > 0) {
        return find_edge(a, single);
    }
    int all_edges = num_edge(a, b);
    // l - bad, r - ok
    while (r - l > 1) {
        int mid = (l + r) / 2;
        vector < int > sub;
        for (int i = 0; i <= mid; i++) sub.push_back(b[i]);
        if (num_edge(a, sub) == all_edges) r = mid;
        else l = mid;
    }
    vector < int > new_single;
    new_single.push_back(b[r]);
    assert(num_edge(a, new_single) > 0);
    return find_edge(a, new_single);
}
int sz = 0;
vector < int > cur_comp;
int comp[maxN];
vector < int > comps[maxN];
int prv[maxN];
int clr[maxN];
vector < int > g[maxN];
void build_comp(vector < int > all) {
    if (all.empty()) return ;
    sz++;
    cur_comp.clear();
    int ind = rand() % all.size();
    comp[all[ind]] = sz;
    prv[all[ind]] = -1;
    cur_comp.push_back(all[ind]);
    vector < int > nall;
    for (int v : all) {
        if (v == all[ind]) continue;
        nall.push_back(v);
    }
    swap(all, nall);
    while (1) {
        if (all.empty()) break;
        if (num_edge(all, cur_comp) == 0) break;
        auto t = find_edge(all, cur_comp);
        int a = t.first;
        int b = t.second;
        if (comp[a] != sz) swap(a, b);
        comp[b] = sz;
        clr[b] = clr[a] ^ 1;
        cur_comp.push_back(b);
        vector < int > nall;
        prv[b] = a;
        g[a].push_back(b);
        g[b].push_back(a);
        for (int v : all) {
            if (v == b) continue;
            nall.push_back(v);
        }
        swap(all, nall);
    }
    comps[sz] = cur_comp;
    build_comp(all);
}
vector < int > ans;
bool used[maxN];
void solve(vector < int > all) {
    vector < int > by_c[2];
    for (int v : all) {
        by_c[clr[v]].push_back(v);
    }
    if ((ask(by_c[0]) == 0) && (ask(by_c[1]) == 0)) {
        for (int v : by_c[0]) ans.push_back(v);
        return ;
    }
    pair < int, int > t = make_pair(-1, -1);
    vector < int > will = by_c[0];
    if (ask(by_c[0]) == 0)  will = by_c[1];
    int l = 0;
    int r = will.size() - 1;
    while (r - l > 1) {
        //cout << l << " " << r << " HERE" << endl;
        vector < int > pos_all;
        int mid = (l + r) / 2;
        for (int i = 0; i <= mid; i++) pos_all.push_back(will[i]);
        if (ask(pos_all) > 0) r = mid;
        else l = mid;
    }
    vector < int > qq;
    for (int i = 0; i < r; i++) {
        qq.push_back(will[i]);
    }
    vector < int > single;
    single.push_back(will[r]);
    t = find_edge(qq, single);
    int a = t.first;
    int b = t.second;
    vector < int > cyc2, cyc1;
    int lca = -1;
    int copa = a;
    while (copa != -1) {
        used[copa] = true;
        copa = prv[copa];
    }
    int copb = b;
    while (copb != -1) {
        if (used[copb]) {
            lca = copb;
            break;
        }
        copb = prv[copb];
    }
    while (a != lca) {
        cyc1.push_back(a);
        a = prv[a];
    }

    while (b != lca) {
        cyc2.push_back(b);
        b = prv[b];
    }
    reverse(cyc1.begin(), cyc1.end());
    cout << "N " << cyc1.size() + cyc2.size() + 1 << endl;
    for (int v : cyc2) cout << v << " ";
    cout << lca << " ";
    for (int v : cyc1) cout << v << " ";
    cout << endl;
    exit(0);
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    vector < int > all;
    for (int i = 1; i <= n; i++) all.push_back(i);
    build_comp(all);
    for (int i = 1; i <= sz + 2; i++) {
        if (comps[i].empty()) continue;
        solve(comps[i]);
    }
    cout << "Y " << ans.size() << '\n';
    for (int v : ans) cout << v << " ";
    cout << endl;
}