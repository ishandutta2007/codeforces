#include <bits/stdc++.h>

using namespace std;

int n;
int a[1005];
vector<pair<int, int> > ins;

void sim(void) {
    for (auto x: ins) swap(a[x.first], a[x.second]);
    for (int i = 1; i < n; ++i) assert(a[i] <= a[i+1]);
}

bool cmp(pair<int, int> x, pair<int, int> y) {
    if (a[x.first] != a[y.first]) return a[x.first] < a[y.first];
    if (x.first != y.first) return x.first < y.first;
    return x.second > y.second;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) for (int j = i + 1; j <= n; ++j) if (a[i] > a[j]) ins.push_back({i, j});
    sort(ins.begin(), ins.end(), cmp);
    sim();
    cout << ins.size() << '\n';
    for (auto x: ins) cout << x.first << ' ' << x.second << '\n';
    return 0;
}