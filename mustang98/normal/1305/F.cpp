#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, max_v = 2e6, inf = 1000111222;

ll a[max_n];
int n;
mt19937 gen(228);
vector<ll> lsos[max_n * 2];

bool sos[max_v];

void init() {
    sos[0] = sos[1] = 1;
    sos[2] = 0;
    for (ll i = 2; i * i <= max_v; ++i) {
        if (sos[i]) continue;
        for (ll j = i * i; j < max_v; j += i) {
            sos[j] = 1;
        }
    }
}

set<ll> s;

ll dst(ll a, ll pr) {
    if (pr >= a) {
        return pr - a;
    }
    ll val = a % pr;
    return min(val, pr - val);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    init();
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%lld", a + i);
    }
    shuffle(a, a + n, gen);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 1) {
            ++ans;
        }
    }
    ll from = max(1LL, a[0] - ans);
    ll to = a[0] + ans;
    for (int i = 2; i < max_v; ++i) {
        if (sos[i]) continue;
        ll cur = i;
        ll st = from / cur * cur;
        bool cand = 0;
        for (ll x = st; x <= to; x += cur) {
            if (x >= from) {
                lsos[x - from].PB(cur);
                cand = 1;
            }
        }
        if (cand) {
            s.insert(cur);
        }
    }
    for (int i = 0; i <= to - from; ++i) {
        ll cur = from + i;
        for (ll a : lsos[i]) {
            while(cur % a == 0) {
                cur /= a;
            }
        }
        if (cur != 1) {
            s.insert(cur);
        }

    }
    if (s.find(1LL) != s.end()) {
        s.erase(1LL);
    }
    for (ll pr : s) {
        ll cur_ans = 0;
        for (int i = 0; i < n; ++i) {
            cur_ans += dst(a[i], pr);
            if (cur_ans >= ans) {
                break;
            }
        }
        ans = min(ans, cur_ans);
    }
    cout << ans << endl;

    return 0;
}