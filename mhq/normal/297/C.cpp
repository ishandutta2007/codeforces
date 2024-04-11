#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = (int)1e5 + 100;
set < int > frst;
set < int > sec;
int ans[maxN];
int a[maxN];
int n;
void add(int val, int ind) {
    assert(0 <= val && val <= a[ind]);
    frst.insert(val);
    ans[ind] = val;
    sec.insert(a[ind] - val);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    vector < pair < int, int > > f;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = x;
        f.emplace_back(x, i);
    }
    sort(f.begin(), f.end());
    reverse(f.begin(), f.end());
    vector < int > forA, forB;
    for (int i = 0; i < f.size(); i++) {
        if (i % 3 == 0) add(f[i].first / 2, f[i].second);
        else if (i % 3 == 1) forA.push_back(f[i].second);
        else forB.push_back(f[i].second);
    }
    reverse(forA.begin(), forA.end());
    reverse(forB.begin(), forB.end());
    int c = 0;
    for (int ind : forA) {
        while (frst.find(c) != frst.end()) c++;
        add(min(a[ind], c), ind);
    }
    c = 0;
    for (int ind : forB) {
        while (sec.find(c) != sec.end()) c++;
        add(a[ind] - min(a[ind], c), ind);
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
    for (int i = 1; i <= n; i++) {
        cout << a[i] - ans[i] << " ";
    }
    return 0;
}