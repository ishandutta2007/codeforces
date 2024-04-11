#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
 
// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

const ll INF = 1e18;
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    ll n, k, a, b;
    cin >> n >> k >> a >> b;
    ll mn = INF, mx = -1;
    ll len = n * k;

    auto get_del = [&](ll del) {
        ll g = __gcd(del, len);
        return len / g;
    };

    auto get = [&](ll pos) {
        ll del;
        if (pos > a)
            del = pos - a;
        else
            del = len - (a - pos);
        if (del == 0)
            return;
        ll cur_ans = get_del(del);
        mn = min(mn, cur_ans);
        mx = max(mx, cur_ans);
        return;
    };

    for (int i = 0; i < n; i++) {
        ll st = 1ll * i * k;
        get(st + b);
        get(st + k - b);
    }
    cout << mn << ' ' << mx << '\n';
}