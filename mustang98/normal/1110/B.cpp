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

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, k;
    vector<int> v;
    cin >> n >> m >> k;
    ll ans = n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    vector<int> d;
    for (int i = 0; i + 1 < n; ++i) {
        d.push_back(v[i + 1] - v[i]);
    }
    sort(d.begin(), d.end());
    for (int i = 0; i < (n - k); ++i) {
        ans += (d[i] - 1);
    }
    cout << ans;

    return 0;
}