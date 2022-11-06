#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int N = 1e5 + 5;
int n, k, m, a[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<pair<int, int> > s;
    for (int i = 1; i <= n; i++)
        if (s.size() == 0 || s.back().first != a[i])
            s.pb({a[i], 1});
        else {
            s.back().second++;
            if (s.back().second == k)
                s.pop_back();
        }
    if (m == 1) {
        long long sum = 0;
        for (int i = 0; i < s.size(); i++)
            sum += s[i].second;
        cout << sum;
        return 0;
    }
    vector<pair<int, int> > a, b;
    a = s;
    b = s;
    reverse(b.begin(), b.end());
    int pos = -2;
    for (int i = 0; i < a.size(); i++)
        if (b[i].first != a[i].first) {
            pos = i - 1;
            break;
        } else
            if (b[i].second + a[i].second < k) {
                pos = i - 1;
                break;
            } else
                if (b[i].second + a[i].second > k) {
                    pos = i - 1;
                    break;
                }
    if (pos == -2)
        pos = a.size() - 1;
    pos++;
    if (pos >= (a.size() - 1) / 2 + 1) {
        if (m % 2 == 0)
            cout << 0;
        else {
            long long sum = 0;
            for (int i = 0; i < a.size(); i++)
                sum += a[i].second;
            cout << sum;
        }
        return 0;
    }
    if (a.size() % 2 == 1 && pos == a.size() / 2) {
       // cout << 1 << endl;
        if (1ll * m * a[pos].second % k == 0)
            cout << 0;
        else {
            long long sum = 0;
            for (int i = 0; i < a.size(); i++)
                sum += a[i].second;
            sum -= a[pos].second;
            cout << 1ll * m * a[pos].second % k + sum;
        }
        return 0;
    }
    long long k1 = 0, k2 = 0;
    for (int i = 0; i < a.size() - pos; i++)
        k1 += a[i].second;
    for (int i = pos; i < a.size() - pos; i++)
        k2 += a[i].second;
    long long ans = 2ll * k1 + 1ll * (m - 2) * k2;
    if (a[pos].first == b[pos].first && a[pos].second + b[pos].second > k) {
        //cout << k * (m - 1) << endl;
        ans -= 1ll * k * (m - 1);
    }
    cout << ans << endl;
    return 0;
}