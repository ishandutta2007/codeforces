#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pii> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    vector<int> f(n + 1);
    for (int i = 0; i < n; i++) {
        int low = upper_bound(v.begin(), v.end(), pii(v[i].first - v[i].second, -1)) - v.begin();
        f[i + 1] = f[low] + i - low;
    }
    int res = n;
    for (int i = 1; i <= n; i++)
        res = min(res, f[i] + n - i);
    cout << res << endl;
}