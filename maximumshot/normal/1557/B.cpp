#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

void work() {
    cout.precision(20);
    cout << fixed;
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<int> crd = a;
        sort(crd.begin(), crd.end());
        for (auto& x : a)
            x = lower_bound(crd.begin(), crd.end(), x) - crd.begin();
        int total = 1;
        for (int i = 0; i + 1 < n; i++) {
            if (a[i] + 1 != a[i + 1])
                total++;
        }
        cout << (total <= k ? "Yes" : "No") << "\n";
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    work();

    return 0;
}