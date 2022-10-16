#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <ll> vi;
typedef pair <ll, ll> ii;

ll N, K, S, t, maxLen;
vi lengths;
ll s[200005];
ii car[200005];
ll h[200005];

bool check(ll x) {
    int pos = upper_bound(lengths.begin(), lengths.end(), x) - lengths.begin();
    //cout << x << " " << s[K] - s[pos - 1] - (K - pos + 1) * x << endl;
    return s[K] - s[pos - 1] - (K - pos + 1) * x <= t;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K >> S >> t; t -= S;
    ff(i, 1, N) cin >> car[i].first >> car[i].second;
    ff(i, 1, K) cin >> h[i];
    sort(h + 1, h + K + 1);
    h[K+1] = S;
    ff(i, 1, K + 1) lengths.pb(2 * (h[i] - h[i-1])), maxLen = max(maxLen, h[i] - h[i-1]);
    lengths.pb(0);
    sort(lengths.begin(), lengths.end());
    K = lengths.size() - 1;
    ff(i, 1, K) s[i] = s[i-1] + lengths[i];
    sort(car + 1, car + N + 1);
    ff(i, 1, N) if (car[i].second >= maxLen && check(car[i].second)) return cout << car[i].first << endl, 0;
    cout << -1 << endl;
    return 0;
}