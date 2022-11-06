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
vector<pii> f;
int main() {
    string s;
    cin >> s;
    n = s.size();
    ll p = 0;
    char tt = 'x';
    if (n % 4 != 0) {
        p = 1;
        tt = s[n / 2];
    }
    string ans;
    for (int i = 0; i < n; i+=2) {
        for (int j = 0; j < 3; j++) {
            a[j] = 0;
        }
        if (n/2 - i - 2 < 0 || n/2 + i + p + 1 >= n) {
            break;
        }
        //cout << s[n/2 - i - 1] << s[n/2 - i - 2] << s[n/2 + i + p] << s[n/2 + i + p + 1];
        a[s[n/2 - i - 1] - 'a'] |= 1;
        a[s[n/2 - i - 2] - 'a'] |= 1;
        a[s[n/2 + i + p] - 'a'] |= 2;
        a[s[n/2 + i + p + 1] - 'a'] |= 2;
        for (int j = 0; j < 3; j++) {
            if (a[j] == 3) {
                ans.push_back(j + 'a');
                break;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
    if (tt != 'x') {
        cout << tt;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}