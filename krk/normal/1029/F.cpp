#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> llll;

const ll Inf = 1000000000000000000ll;

ll a, b;
vector <llll> V;
ll res = Inf;

int main()
{
    cin >> a >> b;
    for (ll i = 1; i * i <= a; i++) if (a % i == 0)
        V.push_back(llll(i, a / i));
    for (ll i = 1; i * i <= b; i++) if (b % i == 0)
        V.push_back(llll(i, b / i));
    sort(V.begin(), V.end());
    int pnt = 0;
    ll mx = Inf;
    ll c = a + b;
    for (ll i = 1; i * i <= c; i++) if (c % i == 0) {
        while (pnt < V.size() && V[pnt].first <= i) {
            mx = min(mx, V[pnt].second);
            pnt++;
        }
        if (mx <= c / i)
            res = min(res, 2ll * (ll(i) + ll(c / i)));
    }
    cout << res << endl;
    return 0;
}