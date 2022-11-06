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

#define MOD 1000000007
#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef int ll;
using namespace std;
ll n, m, k, x, y, z;
ll a[200500];

int main() {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> x >> y;
        a[x]++;
        a[y]++;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == 2) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}