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

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, ini, fin, t, x, a, b;
    queue<ll> q;

    cin >> ini >> fin >> t >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.push(x);
    }

    ll res, ind;

    if (q.front() > ini)
        res = 0, ind = ini;
    else
        res = ini - (q.front() - 1), ind = q.front()-1; 

    ll u = ini;
    while (q.size()) {
        u = max(u, q.front());

        u += t;
        q.pop();

        if (u + t <= fin) {
            if (q.size() && q.front() <= u) {
                if (res > u - (q.front()-1))
                    res = u - (q.front()-1), ind = q.front()-1;
            } else {
                if (res > 0)
                    res = 0, ind = u;
            }
        }
    }

    cout << ind << endl;

    return 0;
}