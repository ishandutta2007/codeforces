#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

vector<ll> a;
vector<ll> b;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i =0 ; i < n; ++i) {
        ll x;
        cin >> x;
        a.PB(x);
    }
    for (int i =0 ; i < m; ++i) {
        ll x;
        cin >> x;
        b.PB(x);
    }
    sort(a.begin(), a.end());
    while (a.size() >= 2 && a.back() == a[a.size() - 2]) {
        a.pop_back();
    }
    reverse(a.begin(), a.end());
    for (int i = 1; i < a.size(); ++i) {
        a[i] = a[0] - a[i];
        //cout << a[i] << ' ';
    }
    ll g = 0;
    for (int i = 1; i < a.size(); ++i) {
        g = __gcd(g, a[i]);
    }
    //cout << g << endl;
    for (int i = 0; i < m; ++i) {
        ll res = __gcd(b[i] + a[0], g);
        cout << res << ' ';
    }
    cout << endl;

    return 0;
}