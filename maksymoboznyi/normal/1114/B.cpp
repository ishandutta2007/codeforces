#include <bits/stdc++.h>
#define pb push_back
#define int long long

using namespace std;

const int N = 2e5 + 5;

int n, m, k, a[N], used[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int> > v;
    for (int i = 1; i <= n; i++)
        cin >> a[i], v.pb({a[i], i});
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    long long sum = 0;
    for (int i = 0; i < m * k; i++)
        used[v[i].second] = 1, sum += v[i].first;
    cout << sum << endl;
    vector<int> pos;
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        cur += used[i];
        if (cur > m) {
            cur = 1;
            cout << i - 1 << ' ' ;
        }
    }
    return 0;
}