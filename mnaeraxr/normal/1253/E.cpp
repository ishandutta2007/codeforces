#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;

    vector<pii> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end());

    map<pii,int> memo;

    function<int(int,int)> solve = [&](int i, int m) {
        if (m <= 0) {
            return 0;
        } else if (i == 0) {
            return max({0, a[0].first - a[0].second - 1, m - (a[0].first + a[0].second)});
        } else if (memo.find(pii(i, m)) != memo.end()) {
            return memo[pii(i, m)];
        } else {
            int cost = max(0, m - a[i].first - a[i].second);
            int lo = min(m, a[i].first - a[i].second - cost - 1);
            int used = cost + solve(i - 1, lo);
            int complete = cost + max(lo, 0);
            int ans = min({solve(i - 1, m), used, complete});
            return memo[pii(i, m)] = ans;
        }
    };

    cout << solve(n - 1, m) << endl;

    return 0;
}