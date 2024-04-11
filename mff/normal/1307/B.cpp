#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <random>
#include <string>

#define endl '\n'

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;

        vector<int> a(n);

        bool ok = false;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];

            ok |= a[i] == x;
        }

        if (ok) {
            cout << 1 << endl;
        } else {
            int mx = *max_element(a.begin(), a.end());
            cout << max((x + mx - 1) / mx, 2) << endl;
        }
    }

    return 0;
}