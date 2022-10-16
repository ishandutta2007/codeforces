#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N, K;
ll c[500005], ans1, ans2, S;

ll required1(ll x) {
    ll ret = 0;
    ff(i, 1, N) ret += max(0LL, x - c[i]);
    return ret;
}

ll required2(ll x) {
    ll ret = 0;
    ff(i, 1, N) ret += max(0LL, c[i] - x);
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    ff(i, 1, N) cin >> c[i], S += c[i];
    sort(c + 1, c + N + 1);
    ll l = c[1], r = S / N;
    while (l < r) {
        ll m = l + r + 1 >> 1;
        if (required1(m) <= K) l = m; else r = m - 1;
    }
    ans1 = l;
    l = (S - 1 + N) / N, r = c[N];
    while (l < r) {
        ll m = l + r >> 1;
        if (required2(m) <= K) r = m; else l = m + 1;
    }
    ans2 = l;
    cout << ans2 - ans1 << endl;
    return 0;
}