#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MX = 1048576, mod = 1e9+7;
int n, q, l, x, a, p[MX], res[MX];

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    fill(p, p+MX, -1);
    p[0] = 0, res[0] = 1;

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a;

        if (p[a] == -1) {
            for (int j = 0; j < MX; j++)
                if (p[j] != -1 && p[j] < i)
                    p[a ^ j] = i;
            res[i] = res[i-1];
        } else {
            res[i] = (res[i-1] * 2) % mod;
        }
    }

    while (q--) {
        cin >> l >> x;

        if (p[x] != -1 && p[x] <= l)
            cout << res[l] << endl;
        else
            cout << 0 << endl;
    }
}