#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <assert.h>

#define endl '\n'

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while (t--) {

        int n; cin >> n;

        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int mx = -1;
        int mn = 1000000000;

        int bd = 0;

        for (int i = 0; i < n; ++i) {
            if (a[i] == -1) continue;

            if (i > 0 && a[i - 1] != -1)
                bd = max(bd, abs(a[i] - a[i - 1]));

            if ((i > 0 && a[i - 1] == -1) || (i + 1 < n && a[i + 1] == -1)) {
                mx = max(mx, a[i]);
                mn = min(mn, a[i]);
            }
        }

        if (mx == -1) {
            cout << "0 0" << endl;
        } else {
            int tar = (mx + mn) / 2;
            bd = max(bd, mx - tar);
            bd = max(bd, tar - mn);
            cout << bd << " " << tar << endl;
        }
    }

    return 0;
}