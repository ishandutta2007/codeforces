#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 100005;
const int mod = 1000000007;

int n, x, y;
ii lr[Maxn];
multiset <int> S;
ll res;

int main()
{
    scanf("%d %d %d", &n, &x, &y);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &lr[i].first, &lr[i].second);
    sort(lr, lr + n);
    for (int i = 0; i < n; i++) {
        auto it = S.lower_bound(lr[i].first);
        if (it == S.begin()) res = (res + x + ll(y) * (lr[i].second - lr[i].first)) % mod;
        else {
            it--;
            int num = *it; S.erase(it);
            ll cand = min(x + ll(y) * (lr[i].second - lr[i].first), ll(y) * (lr[i].second - num));
            res = (res + cand) % mod;
        }
        S.insert(lr[i].second);
    }
    cout << res << endl;
    return 0;
}