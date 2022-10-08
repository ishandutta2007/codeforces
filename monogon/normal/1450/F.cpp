
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> f(n + 1, 0), ends(n + 1, 0);
    int cuts = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        f[a[i]]++;
        if(i > 0 && a[i] == a[i - 1]) {
            ends[a[i]]++;
            ends[a[i - 1]]++;
            cuts++;
        }
    }
    if(*max_element(f.begin(), f.end()) > (n + 1) / 2) {
        cout << -1 << '\n';
        return;
    }
    ends[a[0]]++;
    ends[a[n - 1]]++;
    int maxf = *max_element(ends.begin(), ends.end());
    cout << cuts + max(0, maxf - cuts - 2) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        solve();
    }
}