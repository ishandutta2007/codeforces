#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define F first
#define S second
int t, n, a[101], d[101];

void dfs(int l, int r, int x) {
    if (l==r) return;
    int mi = l;
    for (int i = l; i < r; i++) {
        if (a[i]>a[mi]) mi=i;
    }
    d[mi]=x;
    dfs(l, mi, x+1);
    dfs(mi+1, r, x+1);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    dfs(0, n, 0);
    for (int i = 0; i < n; i++) cout << d[i] << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}