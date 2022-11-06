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
ll a[1000005], b[1000050];

vector<ll> f, poss_divs, g;

ll get_ans() {
    g.clear();
    g.push_back(0);
    ll ans = 0;
    for (int i = 0; i < f.size(); i++) {
        g.push_back(g.back() + f[i]);
        ans += f[i] * i;
    }
    ll min_ans = ans;
    for (int i = 0; i + 1 < f.size(); i++) {
        ans += g[i+1] - (g.back() - g[i+1]);
        min_ans = min(min_ans, ans);
    }
    return min_ans;

}

ll solve(ll x) {
    for (int i = 0; i < n; i++) {
        b[i] = a[i] % x;
    }
    ll i = 0, cur_sum = 0;
    ll ans = 0;
    f.clear();
    while (i < n) {
        if (cur_sum + b[i] < x) {
            cur_sum += b[i];
            f.push_back(b[i]);
            b[i] = 0;
            i++;
        } else {
            f.push_back(x - cur_sum);
            b[i] -= x - cur_sum;
            cur_sum = 0;
            ans += get_ans();
            f.clear();
        }
    }
    return ans;
}

int main() {
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a[i] = x;
        sum += a[i];
    }
    ll fsum = sum;
    if (sum == 1) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 2; i <= 1000000; i++) {
        if (sum % i == 0) {
            poss_divs.push_back(i);
            while (sum % i == 0) {
                sum /= i;
            }
        }
    }
    if (sum != 1) {
        poss_divs.push_back(sum);
    }

    ll ans = (ll)1e+18;
    for (auto x : poss_divs) {
        ans = min(ans, solve(x));
    }
    cout << ans << endl;
    return 0;
}