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

    int m, c[105], x, y, res = -1, tot = 0, acu = 0;

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> c[i];
        tot += c[i];
    }

    cin >> x >> y;
    for (int i = 0; i < m; i++) {
        if (x <= acu && acu <= y && x <= tot - acu && tot - acu <= y)
            res = i;
        acu += c[i];
    }
    cout << res + 1 << endl;

    return 0;
}