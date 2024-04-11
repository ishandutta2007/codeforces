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

int cnt[max_n];

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
        for (int i = 0; i < 30; ++i) {
            cnt[i] = 0;
        }
        for (int i = 0; i  <n; ++i) {
            int x;
            cin >> x;
            for (int j = 0; j < 30; ++j) {
                if (x & (1 << j)) ++cnt[j];
            }
        }
        vector<int> v;
        for (int i = 0; i < 30; ++i) {
            if (cnt[i]) {
                v.PB(cnt[i]);
            }
        }
        if (v.empty()) {
            for (int i = 0; i < n; ++i) {
                cout << i + 1 << ' ';
            }
            cout << "\n";
            continue;
        }
        sort(v.begin(), v.end());
        int g = v[0];
        for (int i = 1; i < v.size(); ++i) {
            g = __gcd(g, v[i]);
        }
        vector<int> ans;
        for (int i = 1; i * i <= g; ++i) {
            if (g % i == 0) {
                int a = i;
                int b = g / i;
                ans.PB(a);
                if (b != a) {
                    ans.PB(b);
                }
            }
        }
        sort(ans.begin(), ans.end());
        for (int x : ans) {
            cout << x << ' ';
        }
        cout << "\n";

    }
    return 0;
}