#include <sstream>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <vector>
#include <algorithm>
#include <bitset>
#include <utility>
#include <map>
#include <set>

#define MOD 998244353
#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
ll a[200500], b[200500];
ll n, m, i, j, k, x, y, z;

int main() {
    cin >> n >> m;
    ll x = 1;
    for (int i = 0; i < n + m; i++) {
        x = x * 2 % MOD;
    }
    cout << x << endl;
    return 0;
}