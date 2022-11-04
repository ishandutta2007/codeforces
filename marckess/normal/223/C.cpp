#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
 
#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) (((n % k) + k ) % k)

ll pot (ll b, ll p, ll m) {
    ll res = 1;
    while (p) {
        if (p&1)
            res = (res * b) % m;
        b = (b * b) % m;
        p /= 2;
    }
    return res;
}

const int M = 1e9+7;
ll inv[10005];
void obtInv () {
    inv[0] = inv[1] = 1;
    for (int i = 2; i <= 1e4; i++)
        inv[i] = pot(i, M-2, M);
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    obtInv();

    int n, k;
    ll a[2005], s[2005];
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s[i] = 0;

        ll acu = 1, _k = k, _r = 1;
        for (int j = i; j >= 0; j--) {
            s[i] = (s[i] + acu * a[j]) % M;

            acu *= (_k * inv[_r]) % M;
            acu %= M;
            _k++, _r++;
            k %= M;
        }
    }

    for (int i = 0; i < n; i++)
        cout << s[i] << " ";
    cout << endl;

    return 0;
}