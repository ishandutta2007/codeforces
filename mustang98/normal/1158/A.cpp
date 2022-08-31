#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

vector<int> g, b;
int n, m;

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        b.PB(a);
    }
    for (int i = 0; i < m; ++i) {
        int a;
        cin >> a;
        g.PB(a);
    }
    sort(b.begin(), b.end());
    sort(g.begin(), g.end());
    if (b.back() > g[0]) {
        cout << -1 << endl;
        return 0;
    }
    ll ans = 0;
    if (b.back() == g[0]) {
        for (int i = 0; i + 1 < n; ++i) {
            ans += 1LL * m * b[i];
        }
        for (int val : g) {
            ans += val;
        }
    } else {
        reverse(b.begin(), b.end());
        for (int i = 2; i < n; ++i) {
            ans += 1LL * m * b[i];
        }
        for (int i = 1; i < m; ++i) {
            ans += b[1];
            ans += g[i];
        }
        ans += g[0];
        ans += b[0];
    }
    cout << ans << endl;
    return 0;
}