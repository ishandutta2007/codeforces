#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ld = long double;

const ll INF = (ll)2e18 + 100;
const int N = 200 * 1000 + 10;

ll mul(ll a, ll b) {
    if (INF / b < a)
        return INF;
    return min(INF, a * b);
}

ll a[N];
ll s[N];
ll go[N];
int n;
ll k;

ll get_s(int l, int r) {
    ll ans = s[r];
    if (l)
        ans -= s[l - 1];
    return ans;
}


int stupid() {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ll p = 1;
        ll ss = 0;
        for (int j = i; j < n; j++) {
            p *= a[j];
            ss += a[j];
            if (ss * k == p)
                ans++;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    
    for (;;) {
    cin >> n;
    cin >> k;
    //n = 10;
    //k = rand() % 10 + 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        //a[i] = rand() % 10 + 1;
        s[i] = a[i];
    }
    for (int i = 1; i < n; i++)
        s[i] += s[i - 1];
    int last = n;
    go[n] = n;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] > 1)
            last = i;
        go[i] = last;
    }
    int ans = 0;
    for (int l = 0; l < n; l++) {
        ll prod = a[l];
        ll sum = a[l];
        if (prod >= sum * k && prod <= (sum + go[l + 1] - l - 1) * k)
            ans++;
        int r = l;
        for (;;) {
            r = go[r + 1];
            if (r == n)
                break;
            prod = mul(prod, a[r]);
            if (prod >= INF)
                break;
            sum = get_s(l, r);
            if (sum * k <= prod && (sum + go[r + 1] - r - 1) * k >= prod && (sum * k - prod) % k == 0) {
         //       cerr << "L R " <<  l << " " << r << " " << sum << " " << prod << endl;
                ans++;
            }
        }
    }
    /*if (ans != stupid()) {
        cerr << ans << " " << stupid() << endl;
        cerr << n << " " << k <<  endl;
        for (int i = 0; i < n; i++)
            cerr << a[i] << " ";
        cerr << endl;
    }
    assert(ans == stupid());*/
    cout << ans << endl;
    break;
    }
}