#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> ans;
    int mxp = 1;
    for (; 4 * mxp < n; mxp *= 2);
    for (int p = 1; 2 * p < n; p *= 2) {
        for (int i = p; i < 2 * mxp; i += (i % p == p - 1 ? p + 1 : 1)) ans.emplace_back(i + 1, i - p + 1);
    }
    for (int p = 1; 2 * p < n; p *= 2) {
        for (int i = p; i < 2 * mxp; i += (i % p == p - 1 ? p + 1 : 1)) ans.emplace_back(n - i, n - i + p);
    }
    cout << ans.size() << '\n';
    for (auto p : ans) cout << p.first << ' ' << p.second << '\n';
}