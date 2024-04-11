#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, d;
    cin >> n >> d;
    multiset<int> nums;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        nums.insert(temp);
    }
    auto it = nums.begin();
    int a, b;
    a = *it;
    it++;
    b = *it;
    if (a+b <= d) cout << "YES\n";
    else {
        it = nums.end();
        it--;
        if (*it <= d) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}