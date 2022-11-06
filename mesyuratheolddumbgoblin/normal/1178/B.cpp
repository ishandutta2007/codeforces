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

typedef long long ll;
using namespace std;
ll a[200500], b[200500];
ll n, m, i, j, k, x, y, z;

int main() {
    string s;
    cin >> s;
    ll k = 0;
    ll ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'v') {
            k++;
        } else {
            ans += max(k - 1, 0LL);
            k = 0;
        }
    }
    ans += max(k - 1, 0LL);
    ll cur = 0;
    ll tot = 0;
    k = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'v') {
            k++;
        } else {
            cur += max(k - 1, 0LL);
            k = 0;
            tot += cur * (ans - cur);
        }
    }
    cout << tot << endl;
    return 0;
}