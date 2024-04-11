#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll l, r, k;
vector<ll> ans;

int main() {
    cin >> l >> r >> k;
    ll cur = 1;
    while (1) {
        if (l <= cur && cur <= r) ans.push_back(cur);
        if (r / cur < k) break;
        cur *= k;
    }
    if (ans.empty()) cout << "-1\n";
    else {
        for (ll i : ans) cout << i << ' ';
    }
}