#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    int n;
    vector < int > all;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        all.push_back(x);
    }
    sort(all.begin(), all.end());
    for (int i = 0; i < all.size(); i++) {
        int s = 0;
        for (int j = 0; j < all.size(); j++) {
            s += all[j];
        }
        if (s * 2 >= 9 * n) {
            cout << i;
            return 0;
        }
        all[i] = 5;
    }
    cout << all.size();
    return 0;
}