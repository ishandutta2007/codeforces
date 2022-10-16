#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N;
ll K, a[100005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    ff(i, 1, N) cin >> a[i];
    sort(a + 1, a + N + 1);
    ll ans = 0;
    ff(i, 2, N) {
        a[i] -= a[1];
        if (a[i] % K) return cout << -1 << endl, 0;
        ans += a[i] / K;
    }
    cout << ans << endl;
    return 0;
}