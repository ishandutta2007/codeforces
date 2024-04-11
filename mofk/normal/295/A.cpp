#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N, M, K;
ll a[100005];
ll b[100005];

ll l[100005];
ll r[100005];
ll d[100005];
ll c[100005];

ll x[100005];
ll y[100005];

int main(void) {
    cin >> N >> M >> K;
    ff(i, 1, N) cin >> a[i];
    ff(i, 1, N) b[i] = a[i] - a[i-1];
    ff(i, 1, M) cin >> l[i] >> r[i] >> d[i];
    ff(i, 1, K) cin >> x[i] >> y[i];
    ff(i, 1, K) --c[y[i]+1], ++c[x[i]];
    ll s = 0;
    ff(i, 1, M) {
        s += c[i];
        b[r[i]+1] -= s * d[i], b[l[i]] += s * d[i];
    }
    s = 0;
    ff(i, 1, N) { s += b[i]; cout << s << " "; }
    return 0;
}