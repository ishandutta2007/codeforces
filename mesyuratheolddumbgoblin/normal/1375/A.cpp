
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

ll a[15005];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i % 2 && a[i] > 0) {
                a[i] = -a[i];
            }
            if (i % 2 == 0 && a[i] < 0) {
                a[i] = -a[i];
            }
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}