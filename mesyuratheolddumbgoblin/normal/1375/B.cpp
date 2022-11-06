
#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <fstream>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define N 13
#define OFF 400001
#define MOD 998244353
#define C 13000
#define NN 1000000
ll n, m, k, x, y;
ll queries = 0;

ll a[305][305];
ll f(ll x, ll y) {
    ll ans = 4;
    if (x == 0 || x == n-1) {
        ans--;
    }
    if (y == 0 || y == m-1) {
        ans--;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        bool hyu = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
                if (a[i][j] > f(i, j)) {
                    hyu = true;
                } else {
                    a[i][j] = f(i, j);
                }
            }
        }
        if (hyu) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++ ){
                    cout << a[i][j] << " ";
                }
                cout << "\n";
            }
        }
    }

    return 0;
}