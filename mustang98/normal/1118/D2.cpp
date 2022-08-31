#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

ll k;
ll m[max_n];
ll n;

bool check(ll d) {
    ll cnt = n / d;
    ll lft = n % d;
    vector<ll> s;
    for (int i = 0; i < lft; ++i) {
        s.PB(cnt);
    }
    for (int i = cnt - 1; i >= 0; --i) {
        for (ll j = 0; j < d; ++j) {
            s.PB(i);
        }
    }
    if (s.size() != n) {
        exit(228);
    }
    reverse(s.begin(), s.end());
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += max(m[i] - s[i], 0LL);
    }
    return sum >= k;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d", &a);
        m[i] = a;
        sum += m[i];
    }
    if (sum < k) {
        cout << -1;
        return 0;
    }
    sort(m, m + n);
    reverse(m, m + n);
    int l = 0, r = n;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << endl;
    return 0;
}