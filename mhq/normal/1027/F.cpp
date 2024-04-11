#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define rank pankshpank
const int maxN = (int)1e6 + 10;
int n;
int a[maxN], b[maxN];
int sz = 1;
vector < int > g[2 * maxN];
vector < pair < int, int > > all;
int val[2 * maxN];
int p[3 * maxN];
int bad_comp = 0;
int all_sz[3 * maxN];
int student[3 * maxN];
int st = 0;
void build_set(int i) {
    p[i] = i;
    if (i >= st) {
        student[i] = 1;
        bad_comp++;
    }
    else student[i] = 0;
    all_sz[i] = 1;
}
int find_set(int i) {
    if (p[i] == i) return i;
    p[i] = find_set(p[i]);
    return p[i];
}
void unite(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return ;
    if (all_sz[a] < all_sz[b]) swap(a, b);
    int cnt1 = (all_sz[a] < 2 * student[a]);
    int cnt2 = (all_sz[b] < 2 * student[b]);
    bad_comp -= (cnt1 + cnt2);
    all_sz[a] += all_sz[b];
    student[a] += student[b];
    p[b] = a;
    bad_comp += (all_sz[a] < 2 * student[a]);
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        all.emplace_back(a[i], i);
        all.emplace_back(b[i], i);
    }
    sort(all.begin(), all.end());
    int ind = 0;
    while (ind < all.size()) {
        int j = ind;
        while (j < all.size() && all[ind].first == all[j].first) j++; j--;
        val[sz] = all[ind].first;
        for (int i = ind; i <= j; i++) {
            g[sz].push_back(all[i].second);
        }
        ind = j + 1;
        sz++;
    }
    sz--;
    st = 1 + sz;
    for (int i = st; i < n + st; i++) {
        build_set(i);
    }
    for (int i = 1; i <= sz; i++) {
        build_set(i);
        for (int to : g[i]) {
            unite(i, to + st - 1);
        }
        if (bad_comp == 0) {
            cout << val[i] << '\n';
            return 0;
        }
    }
    cout << -1;
    return 0;
}