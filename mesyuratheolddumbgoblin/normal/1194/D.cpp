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
ll n, m, k, x, y, z, q;
ll a[500500], cc[500500];
vector<vector<ll> > b;

int main() {
    ll m;
    cin >> m;
    while (m--) {
        cin >> n >> k;
        if (k % 3 == 0) {
            if (n % (k + 1) % 3 == 0 && n % (k + 1) != k) {
                cout << "Bob" << endl;
            } else {
                cout << "Alice" << endl;
            }
        } else if (n % 3 == 0) {
            cout << "Bob" << endl;
        } else {
            cout << "Alice" << endl;
        }
    }
    return 0;
}