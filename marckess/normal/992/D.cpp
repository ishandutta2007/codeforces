#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const ll lim = 2'000'000'000'000'000'000;
const int MX = 200005;
int n, sig[MX];
ll a[MX], res = 0, p, s, k;

bool desborda (ll a, ll b, ll lim) {
    return !b || a > lim / b;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sig[n] = n;
    for (int i = n - 1; i >= 0; i--)
        sig[i] = a[i] > 1 ? i : sig[i+1];

    for (int i = 0, j; i < n; i++) {
        j = i, p = 1, s = 0;

        while (j < n) {
            if (a[j] == 1) {
                int e = sig[j] - j - 1;
                s++;
                res += p % k == 0 && p <= k * (s + e) && s * k <= p;
                s += e;
                j = sig[j];
            } else {
                if (desborda(p, a[j], lim))
                    break;
                p *= a[j];
                s += a[j];
                res += p == k * s;
                j++;
            }
        }
    }

    cout << res << endl;

    return 0;
}