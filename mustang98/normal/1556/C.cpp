#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 1011;

ll m[max_n];
ll ans = 0;

void upd(ll a, ll b, ll sum, ll mn, int i, int j) {
    ll l = abs(mn);
    if (sum > 0) {
        a -= l;
        b -= (l + sum);
    } else {
        sum = abs(sum);
        if (l <= sum) {
            a -= sum;
        } else {
            a -= l;
            b -= (l - sum);
        }
    }
    if (a < 0 || b < 0) {
        return;
    }
    ll cur = min(a, b) + 1;
    if (i + 1 == j) {
        --cur;
    }
    //cout << "$ " << cur << endl;
    ans += cur;
}

int main() {
    //freopen("input.txt", "r", stdin)
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
    }
    for (int i = 0; i < n; i += 2) {
        ll sum = 0, mn = 0;
        for (int j = i + 1; j < n; ++j) {
            if (j % 2 == 1) {
                //cout << i << ' ' << j << ' ' << sum << ' ' << mn << endl;
                upd(m[i], m[j], sum, mn, i, j);
            }
            if (j % 2 == 0) {
                sum += m[j];
            } else {
                sum -= m[j];
            }
            mn = min(mn, sum);
        }
    }
    cout << ans << endl;
    return 0;
}