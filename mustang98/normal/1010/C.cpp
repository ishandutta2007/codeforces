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

bool vis[max_n];

int m[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    vector<int> g;
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
        g.PB(__gcd(k, m[i]));
    }
    int gg = g[0];;
    for (int i = 1; i < n; ++i) {
        gg = __gcd(gg, g[i]);
    }

    vector<int> ans;
    for (int i = 0; i < k; i += gg) {
        ans.PB(i);
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
    }

    return 0;
}