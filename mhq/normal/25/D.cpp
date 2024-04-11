#include <bits/stdc++.h>
using namespace std;
int n;
const int maxN = 1005;
int parent[maxN];
int rnk[maxN];
void make_set(int v) {
    parent[v] = v;
    rnk[v] = 0;
}
int find_set(int v) {
    if (v == parent[v])
            return v;
    return parent[v] = find_set(parent[v]);
}
void unite_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b])
            ++rnk[a];
    }
}
vector < pair < int, int > > extra;
vector < int > t;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        make_set(i);
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (find_set(a) == find_set(b)) {
            extra.push_back(make_pair(a, b));
        }
        else {
            unite_sets(a, b);
        }
    }
    for (int i = 1; i <= n; i++) {
        int x = find_set(i);
        bool ok = false;
        for (int j = 0; j < t.size(); j++) {
            if (x == t[j]) ok = true;
        }
        if (!ok) t.push_back(x);
    }
    cout << t.size() - 1 << '\n';
    for (int i = 0; i + 1 < t.size(); i++) {
        cout << extra[i].first << " " << extra[i].second << " " << t[i] << " " << t[i + 1] << '\n';
    }
    return 0;
}