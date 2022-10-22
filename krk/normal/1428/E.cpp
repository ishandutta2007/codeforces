#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, int> lli;

const int Maxn = 100005;

int n, k;
int a[Maxn], t[Maxn];
priority_queue <lli> Q;
ll res;

ll Get(ll x, ll p)
{
    ll all = x / p;
    ll a = x % p;
    return ll(all + 1ll) * ll(all + 1ll) * a + ll(all) * ll(all) * (p - a);
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        t[i] = 1;
        res += Get(a[i], 1);
        Q.push(lli(Get(a[i], 1) - Get(a[i], 2), i));
    }
    while (n < k) {
        lli p = Q.top(); Q.pop();
        res -= p.first;
        t[p.second]++;
        Q.push(lli(Get(a[p.second], t[p.second]) - Get(a[p.second], t[p.second] + 1), p.second));
        n++;
    }
    cout << res << endl;
    return 0;
}