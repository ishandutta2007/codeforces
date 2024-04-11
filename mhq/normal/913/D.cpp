#include <bits/stdc++.h>
using namespace std;
int n, T;
int a[2 * (int)1e5 + 10];
int t[2 * (int)1e5 + 10];
vector < int > c[2 * (int)1e5 + 10];
bool check(int x) {
    vector < int > p;
    for (int i = x; i <= n; i++) {
        for (int j = 0; j < c[i].size(); j++) {
            p.push_back(t[c[i][j]]);
        }
    }
    if (p.size() < x) return false;
    sort(p.begin(), p.end());
    int sum = 0;
    for (int i = 0; i < x; i++) {
        sum += p[i];
    }
    if (sum <= T) return true;
    return false;
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> T;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cin >> t[i];
        c[a[i]].push_back(i);
    }
    int l = 0;
    int r = n;
    int sum = 0;
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        if (a[i] < n) ok = false;
        sum += t[i];
        if (sum > T) ok = false;
    }
    if (ok) {
        cout << n << '\n';
        cout << n << '\n';
        for (int i = 1; i <= n; i++) {
            cout << i << " ";
        }
        return 0;
    }
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if (check(mid)) {
            l = mid;
        }
        else r = mid;
    }
    cout << l << '\n';
    cout << l << '\n';
    vector < pair < int, int > > p;
    for (int i = l; i <= n; i++) {
        for (int j = 0; j < c[i].size(); j++) {
            p.push_back(make_pair(t[c[i][j]], c[i][j]));
        }
    }
    sort(p.begin(), p.end());
    for (int i = 0; i < l; i++) {
        cout << p[i].second << " ";
    }
    return 0;
}