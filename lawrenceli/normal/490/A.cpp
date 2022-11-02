#include <bits/stdc++.h>

using namespace std;

vector<int> v[3];

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    int n; cin >> n;
    for (int i=1; i<=n; i++) {
        int t; cin >> t;
        v[t-1].push_back(i);
    }

    int m = min(min(v[0].size(), v[1].size()), v[2].size());
    cout << m << '\n';
    for (int i=0; i<m; i++) {
        for (int j=0; j<3; j++) cout << v[j][i] << ' ';
        cout << '\n';
    }
}