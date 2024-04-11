#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define F first
#define S second
int n, q, k, nums[100002], prefix[100002], l, r;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q >> k;
    for (int i = 1; i <= n; i++) cin >> nums[i];
    nums[0]=0;
    nums[n+1]=k+1;
    prefix[0]=0;
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i-1]+nums[i+1]-nums[i-1]-2;
    }
    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        int ans = prefix[r] - prefix[l-1] + nums[l-1] + k - nums[r+1]+1;
        cout << ans << '\n';
    }
}