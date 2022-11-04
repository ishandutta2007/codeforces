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

    int n, _[5] = {0}, x, res = 0;

    cin >> n;
    while (n--) {
        cin >> x;
        _[x]++;
    }

    x = min(_[1], _[2]);
    _[1] -= x;
    _[2] -= x;
    res += x;
    _[3] += x;

    if (_[1]) {
        x = _[1] / 3;
        _[1] -= 3 * x;
        _[3] += x;
        res += 2 * x;

        if (_[1] == 2) {
            if(_[4] || _[3] > 1) {
                res += 2;
            } else {
                res = -1;
            }
        } else if (_[1] == 1) {
            if (_[3]) {
                res += 1;
            } else if (_[4] > 1){
                res += 2;
            } else {
                res = -1;
            }
        }
    } else if (_[2]) {
        x = _[2] / 3;
        _[2] -= 3 * x;
        _[3] += x * 2;
        res += x * 2;

        if (_[2] == 2) {
            res += 2;
        } else if (_[2] == 1) {
            if (_[4])
                res += 1;
            else if (_[3] > 1)
                res += 2;
            else
                res = -1;
        }
    }

    cout << res << endl;

    return 0;
}