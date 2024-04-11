#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

ll p, k;
vector<ll> res;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> p >> k;

    res.push_back(p%k);
    if (p/k > 0)
        res.push_back(-(p/k));

    while (res.back() < 0 || res.back() >= k) {
        if (res.back() < 0) {
            ll d = ceil(abs(res.back()) / ld(k));

            res[res.size()-1] += d * k;
            res.push_back(d);
        } else {
            ll d = abs(res.back() / k);

            res[res.size()-1] -= d * k;
            res.push_back(-d);
        }
    }

    cout << res.size() << endl;
    for (int x : res)
        cout << x << " ";
    cout << endl;

    return 0;
}