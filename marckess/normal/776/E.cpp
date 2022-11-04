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

vi pr;
bitset<1000005> bs;
void criba () {
    for (ll i = 2; i < 1e6; i++) {
        if (!bs[i]) {
            pr.push_back(i);
            for (ll j = i*i; j < 1e6; j += i)
                bs[j] = 1;
        }
    }
}

ll phi (ll n) {
    ll res = n;
    for (int i = 0; i < pr.size() && ll(pr[i]) * pr[i] <= n; i++) {
        if (n % pr[i] == 0)
            res -= res / pr[i];
        while (n % pr[i] == 0)
            n /= pr[i];
    }

    if (n > 1)
        res -= res / n;

    return res;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    criba();

    ll n, k;
    cin >> n >> k;
    while (k >= 1 && n > 1) {
        n = phi(n);
        k -= 2;
    }
    cout << n % 1000000007 << endl;

    return 0;
}