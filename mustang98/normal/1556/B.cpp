#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 100111;
ll inf = 1e18;

vector<int> v[2];
vector<int> p[2];

ll calc(vector<int> a, vector<int> b) {
    ll ans = 0;
    if (a.size() != b.size()) {
        return inf;
    }
    for (int i = 0; i < a.size(); ++i) {
        ans += abs(a[i] - b[i]);
    }
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        v[0].clear();
        v[1].clear();
        p[0].clear();
        p[1].clear();

        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            p[i % 2].PB(i);
            v[a % 2].PB(i);
        }
        if (abs(int(v[0].size()) - int(v[1].size())) > 1) {
            puts("-1");
            continue;
        }
        ll ans = inf;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                ans = min(ans, calc(v[i], p[j]));
            }
        }
        cout << ans << "\n";
    }

    return 0;
}