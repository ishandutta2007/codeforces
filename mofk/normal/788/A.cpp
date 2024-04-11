#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N;
int a[100005];
int b[100005];
ll s[100005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    ff(i, 1, N) cin >> a[i];
    ff(i, 1, N - 1) b[i] = abs(a[i] - a[i+1]);
    ff(i, 1, N - 1) s[i] = s[i-1] + b[i] * (i % 2 ? 1 : -1);
    ll ans = max(0LL, s[1]), maxl = s[1], minc = 0;
    ff(i, 2, N - 1) {
        ans = max(ans, max(s[i] - minc, maxl - s[i]));
        if (i % 2 == 0) minc = min(minc, s[i]);
        else maxl = max(maxl, s[i]);
    }
    cout << ans << endl;
    return 0;
}