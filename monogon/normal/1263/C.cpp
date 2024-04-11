
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> v = {0};
        for(int i = 1; i * i <= n; i++) {
            v.push_back(n / i);
            v.push_back(n / (n / i));
            v.push_back(n / ((n + i - 1) / i));
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        cout << v.size() << "\n";
        for(int x : v) {
            cout << x << " ";
        }
        cout << "\n";
    }
}