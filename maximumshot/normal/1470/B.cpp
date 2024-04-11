#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

int f(int x) {
    for (int p = 2; p * p <= x; p++) {
        int p2 = p * p;
        while (x % p2 == 0)
            x /= p2;
    }
    return x;
}

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
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i] = f(a[i]);
//            cout << a[i] << " ";
        }
//        cout << "\n";
        sort(a.begin(), a.end());
        int mx_odd = 0;
        int sm_even = 0;
        int mx = 0;
        int cnt1 = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                cnt1++;
                continue;
            }
            int j = i;
            while (j < n && a[i] == a[j])
                j++;
            j--;
            int cnt = j - i + 1;
            mx = max(mx, cnt);
            if (cnt % 2)
                mx_odd = max(mx_odd, cnt);
            else
                sm_even += cnt;
            i = j;
        }
        int q;
        cin >> q;
        while (q--) {
            ll w;
            cin >> w;
            if (w == 0) {
                cout << max(mx, cnt1) << "\n";
            } else {
                cout << max(sm_even + cnt1, mx_odd) << "\n";
            }
        }
    }

    return 0;
}