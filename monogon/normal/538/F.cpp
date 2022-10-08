
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

const int N = 2e5 + 5;
int n, a[N], bit[N], ans[N];

int getSum(int k) {
    int s = 0;
    while(k >= 1) {
        s += bit[k];
        k -= k & -k;
    }
    return s;
}
void add(int k, int x) {
    while(k <= n) {
        bit[k] += x;
        k += k & -k;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector<pii> ve;
    rep(i, 1, n + 1) {
        cin >> a[i];
        ve.emplace_back(a[i], i);
    }
    sort(ve.begin(), ve.end());
    for(auto &p : ve) {
        int i = p.se;
        for(int k = 1; k * (i - 1) + 2 <= n && k <= n - 1; k++) {
            ans[k] += getSum(min(n, k * i + 1)) - getSum(k * (i - 1) + 1);
        }
        add(i, 1);
    }
    rep(k, 1, n) {
        cout << ans[k] << ' ';
    }
    cout << '\n';
}