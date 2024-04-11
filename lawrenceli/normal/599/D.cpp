#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    ll x;
    ll sum1 = 0, sum2 = 0;
    cin >> x;

    vector<pair<ll, ll> > ans;
    for (int i = 1; 1; i++) {
        sum1 += ll(i)*i;
        sum2 += i;

        if (sum1 > x) break;
        if ((x - sum1) % sum2 == 0) {
            ll d = (x - sum1) / sum2;
            ans.push_back(make_pair(i, i + d));
            ans.push_back(make_pair(i + d, i));
        }
    }

    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first << ' ' << ans[i].second << '\n';
}