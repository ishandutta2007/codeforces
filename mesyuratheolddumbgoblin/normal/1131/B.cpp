#include <string>
#include <time.h>
#include <vector>
#include <algorithm>
#include <bitset>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <cmath>

#define pii pair<ll,ll>
#define MOD 1000000007
#define mp make_pair
#define X first
#define Y second
typedef int ll;
using namespace std;
ll n,m,k, y, z, l, i, j, x;
ll a[100500], b[100500];
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    ll lx = 0, ly = 0;
    k = 1;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        if (lx == ly)
            k--;
        k += max(0, min(x, y) - max(lx, ly) + 1);
        lx = x; ly = y;
    }
    cout << k << endl;
    return 0;
}