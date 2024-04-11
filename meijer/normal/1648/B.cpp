#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MX = 1e6+10;

int t, n, c;
int has[MX];

signed main() {
    cin >> t;
    while (t--) {
        cin >> n >> c;
        vector<int> a;
        for (int i=0; i<n; i++) {
            int x; cin >> x;
            a.push_back(x);
        }
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        n = a.size();

        for (int i=0; i<=c; i++) has[i] = 0;
        for (int i=0; i<n; i++) has[a[i]] = 1;
        
        vector<int> posz;
        for (int i=1; i<=c; i++)
            if (!has[i])
                posz.push_back(i);

        for (int i=1; i<=c; i++) has[i] += has[i-1];

        int found = 0;
        for (int z : posz) {
            for (int y : a) {
                if (z * y > c) break;
                int tot = has[min(c, (z+1)*y - 1)] - has[z*y - 1];
                if (tot) {
                    found = 1;
                    break;
                }
            }
            if (found)
                break;
        }
        cout << (found ? "No" : "Yes") << endl;
    }

}