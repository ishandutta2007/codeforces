#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int prev = 0, local=1, global=1;
    for (int i : nums) {
        if (i==prev) {
            local++;
            global = max(local, global);
        } else {
            prev = i;
            local=1;
        }
    }
    cout << global << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}