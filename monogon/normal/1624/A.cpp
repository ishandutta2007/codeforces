
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    cout << *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end()) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te = 1; cin >> te;
    while(te--) solve();
}