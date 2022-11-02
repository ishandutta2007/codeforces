#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define F first
#define S second
int t, n, x;

void solve() {
    cin >> n >> x;
    vector<pi> nums(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> nums[i].F;
        nums[i].S=1;
    }
    int r = 0;
    bool update = true;
    while (r<nums.size()) {
        if (nums[r].F%x != 0) update = false;
        ans += nums[r].F * nums[r].S;
        if (update) nums.pb(mp(nums[r].F/x, nums[r].S*x));
        r++;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}