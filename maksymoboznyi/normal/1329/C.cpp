#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = (1 << 20) + 5;

int n, h, g, dep[N], a[N], sz[N], ans[N];

vector<pair<int, int> > q;
void f(int v) {
    if ((v + v > n || a[v + v] == 0) && (v + v + 1 > n || a[v + v + 1] == 0))
        return void(a[v] = 0);
    if (a[v + v] > a[v + v + 1])
        a[v] = a[v + v], f(v + v);
    else
        a[v] = a[v + v + 1], f(v + v + 1);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
    cin >> h >> g;
    n = (1 << h) - 1;
    q.clear();
    for (int i = 1; i <= n; i++) {
        dep[i] = 0;
        ans[i] = 0;
        sz[i] = 0;
        cin >> a[i];
        q.pb({a[i], i});
        int j = i;
        while (j > 0)
            dep[i]++, j /= 2;
    }
    sort(q.begin(), q.end());
    int sum = 0;
    for (auto p: q) {
        int pos = p.second;
        while (pos != 0) {
            if (dep[pos] > g) {
                pos /= 2;
                continue;
            }
            int val = (1 << (g - dep[pos])) - 1;

            if ((dep[pos] == g || (sz[pos + pos] == val && sz[pos + pos + 1] == val)) && ans[pos] == 0) {
                ans[pos] = p.first;
                sum += ans[pos];
                break;
            }
            pos /= 2;
        }
        while (pos != 0) {
            sz[pos]++;
            pos /= 2;
        }
    }
    cout << sum << "\n";
    for (int i = 1; i < (1 << g); i++)
        while (a[i] != ans[i])
            cout << i << ' ', f(i);
    cout << "\n";
    }
    return 0;
}