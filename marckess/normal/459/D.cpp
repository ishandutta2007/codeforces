#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S |= (1 << j ) )
#define LSB(S) (S & (-S))

struct BIT {
    vector<ll> ft;

    BIT (int n) : ft(n+1) {}

    void update (int k, ll val) {
        while (k < ft.size()) {
            ft[k] += val;
            k += LSB(k);
        }
    }

    ll query (int k) {
        ll sum = 0;
        while (k) {
            sum += ft[k];
            k -= LSB(k);
        }
        return sum;
    }

};

int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    map<int, ll> m, ap;

    cin >> n;

    vi a(n), conj(n), ca(n), cb(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        conj[i] = a[i];
    }

    sort(conj.begin(), conj.end());
    int tam = unique(conj.begin(), conj.end()) - conj.begin();

    BIT acu(n+2);
    for (int i = 0; i < n; i++) {
        int u = a[i] = lower_bound(conj.begin(), conj.begin() + tam, a[i]) - conj.begin();
        u = ++ca[u];
        acu.update(u, 1);
    }

    ll res = 0;
    for (auto u : a) {
        acu.update(ca[u], -1);
        ca[u]--;
        cb[u]++;
        res += acu.query (cb[u]-1);
    }

    cout << res << endl;

    return 0;
}