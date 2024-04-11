#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN (1<<20)
#define MOD 1000000007
#define N 1048576
ll n, x, k, z, m, pos, q, ans_v;
ll x1, p1, x2, p2;
map<ll, ll> g[600500];
ll a[600500], b[600500], p[600500],used[600500];
vector<ll> divs[100500];
vector<ll> f;
ll pw(ll x, ll y) {
    ll s = 1;
    while (y--) {
        s *= x;
        if (s > 1LL * 100000 * 100000) {
            s = 100000LL * 100000LL + 1;
        }
    }
    return s;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a[x]++;
    }
    if (k == 2) {
        for (int i = 1; i <= 100000; i++) {
            for (int j = i; j <= 100000; j+=i) {
                divs[j].push_back(i);
            }
        }
        for (int i = 1; i <= 100000; i++) {
            used[i] = 0;
        }
        ll ans = 0;
        for (ll i = 1; i <= 100000; i++) {
            f.clear();
            for (auto x : divs[i]) {
                for (auto y : divs[i]) {
                    ll l = x * y;
                    ll z = i * i / l;
                    if (l <= 100000 && z <= 100000) {
                        if (used[l] != i) {
                            used[l] = used[z] = i;
                            if (l != z) {
                                ans += a[l] * a[z];
                            } else {
                                ans += a[l] * (a[l] - 1) / 2;
                            }
                        }
                    }
                }
            }
        }
        cout << ans << endl;
        return 0;
    }
    ll ans = 0;
    for (int i = 1; ; i++) {
        ll z = pw(i, k);
        if (z > 100000LL * 100000LL) {
            break;
        }
        for (ll j = 1; j * j <= z; j++) {
            if (z % j == 0) {
                ll y = z / j;
                if (y <= 100000) {
                    if (used[y] != i) {
                        used[y] = used[j] = i;
                        if (y != j) {
                            ans += a[y] * a[j];
                        } else {
                            ans += a[j] * (a[j] - 1) / 2;
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}