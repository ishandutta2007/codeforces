#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

int a[max_n];
int ans[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            v.emplace_back(a[i], i);
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        int base = 0;
        vector<int> x;
        for (int i = 1; i <= n + 1; ++i) {
            x.push_back(i);
            x.push_back(-i);
        }
        ll res = 0;
        int i = 0;
        for (pair<int, int> p : v) {
            int ind = p.S;
            int cnt = p.F;
            ans[ind] = x[i++];
            //cout << ans[ind] << ' ' << a[ind] << endl;
            res += 1LL * abs(ans[ind]) * a[ind];
        }
        cout << res * 2 << "\n";
        cout << 0 << ' ';
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << ' ';
        }
        cout << "\n";

    }


    return 0;
}