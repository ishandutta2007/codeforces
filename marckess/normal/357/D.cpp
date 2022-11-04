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

ll gcd (ll a, ll b) {
    return b ? gcd(b, a%b) : a;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, m;
    string x, y;

    cin >> n >> m >> x >> y;

    ll d = gcd(x.size(), y.size()), rep = n / (y.size() / d);

    vvi cub(d, vi(27));
    for (int i = 0; i < x.size(); i++)
        cub[i % d][x[i]-'a']++;

    ll res = 0;
    for (int i = 0; i < y.size(); i++)
        res += (x.size() / d - cub[i%d][y[i]-'a']) * rep;
    cout << res << endl;

    return 0;
}