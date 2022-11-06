
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
#define NN 1000000
ll n, m, k, x, y;
ll queries = 0;

pii a[5];
ll get_our(ll x) {
    for (int i = 0; i < 3; i++) {
        if (a[i].Y == x) {
            return i;
        }
    }
}
int main() {
    //ios_base::sync_with_stdio(false); cin.tie(0);
    for (int i = 0; i < 3; i++) {
        cin >> a[i].X;
        a[i].Y = i + 1;
    }
    sort(a, a+3);
    cout << "First\n";
    ll A = a[0].X;
    ll B = a[1].X;
    ll C = a[2].X;
    cout << 2 * C - B - A << "\n";
    fflush(stdout);
    cin >> x;
    if (get_our(x) == 0) {
        cout << A + (2 * C - B - A) - C << "\n";
        fflush(stdout);
        cin >> x;
        return 0;
    }

    if (get_our(x) == 1) {
        cout << B + (2 * C - B - A) - C << "\n";
        fflush(stdout);
        cin >> x;
        return 0;
    }

    cout << 6 * C - 3 * B - 3 * A << "\n";
    fflush(stdout);
    cin >> x;
    if (get_our(x) == 0) {
        cout << (A + (6 * C - 3 * B - 3 * A) - B) / 2 << "\n";
        fflush(stdout);
        cin >> x;
        return 0;
    }
    if (get_our(x) == 1) {
        cout << (B + (6 * C - 3 * B - 3 * A) - A) / 2 << "\n";
        fflush(stdout);
        cin >> x;
        return 0;
    }
    return 0;
}