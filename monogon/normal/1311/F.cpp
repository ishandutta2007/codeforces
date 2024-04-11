
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n;
ll x[N], v[N];
vector<pair<ll, ll>> vec;

ll solve(int l, int r) {
    if(l == r) return 0;
    int m = (l + r) / 2;
    ll val = solve(l, m) + solve(m + 1, r);
    ll xsum = 0;
    for(int i = l; i <= m; i++) xsum += vec[i].second;
    int i = l;
    for(int j = m + 1; j <= r; j++) {
        while(i <= m && vec[i] <= vec[j]) {
            xsum -= vec[i].second;
            i++;
        }
        val += (m + 1 - i) * vec[j].second - xsum;
    }
    inplace_merge(vec.begin() + l, vec.begin() + m + 1, vec.begin() + r + 1);
    return val;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        vec.emplace_back(x[i], v[i]);
    }
    sort(vec.begin(), vec.end());
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ans += vec[i].first * (2 * i - n + 1);
        vec[i] = {vec[i].second, vec[i].first};
    }
    cout << (ans - solve(0, n - 1)) << endl;
}