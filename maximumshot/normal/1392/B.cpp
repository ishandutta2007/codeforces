#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if (k % 2) k = 1;
        else k = 2;
        while (k--) {
            int mx = *max_element(a.begin(), a.end());
            for (auto& x : a)
                x = mx - x;
        }
        for (auto x : a)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}