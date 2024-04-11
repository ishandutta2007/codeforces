#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using ll = int64_t;
using ld = long double;
using ull = uint64_t;
using namespace std;
using namespace __gnu_pbds;

const int MAXN = 100228;

const int B = 61;
    
vector<ll> h[B];

const ll GUARD = -1;

int main() {
#ifdef BZ
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20);
    int n;
    cin >> n;


    for (int i = 0; i < n; ++i) {
        ll b;
        cin >> b;
        int p = 0;
        while ((1ll << p) <= b) {
            ++p;
        }

        --p;

        h[p].push_back(b);
    }

    vector<ll> ans;
    for (int bt = 59; bt >= 0; --bt) {
        ll val = (1ll << bt);

        int pos = 0;
        vector<ll> nans;

        for (ll x : h[bt]) {
            nans.push_back(x);
            if (pos > ans.size()) {
                cout << "No\n";
                return 0;
            }

            while (pos != ans.size() && (ans[pos] & val) == 0) {
                nans.push_back(ans[pos++]);
            }

            if (pos != ans.size()) {
                nans.push_back(ans[pos]);
            }
            
            ++pos;
        }

        while (pos < ans.size()) {
            nans.push_back(ans[pos++]);
        }

        ans = move(nans);
    }

    cout << "Yes\n";
    for (ll x : ans) {
        cout << x << " ";
    }
    
}