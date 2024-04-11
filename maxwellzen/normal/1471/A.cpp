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
    vi nums(n);
    ll sum = 0;
    ll maxi = 0;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        sum += nums[i];
        maxi += (nums[i]-1)/x + 1;
    }
    cout << (sum-1)/x + 1 << " " << maxi << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}