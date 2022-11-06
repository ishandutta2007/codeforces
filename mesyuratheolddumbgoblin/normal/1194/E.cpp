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
bitset<5001> vers0[5001];

bitset<2501> vers1[5001];

bitset<1251> vers2[5001];
struct seg {
    ll l;
    ll r;
    ll z;
};
seg h[5005], v[5005];
ll szv, szh;
bool inter(seg x, seg y) {
    return (x.z >= y.l && x.z <= y.r && y.z >= x.l && y.z <= x.r);
}
int main() {
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a == c) {
            if (b > d) {
                swap(b, d);
            }
            h[szh++] = {b, d, a};
        } else {
            if (a > c) {
                swap(a, c);
            }
            v[szv++] = {a, c, b};
        }
    }
    for (int i = 0; i < szh; i++) {
        for (int j = 0; j < szv; j++) {
            if (inter(h[i], v[j])) {
                if (szv < 1250) {
                    vers2[i][j] = 1;
                } else if (szv < 2500) {
                    vers1[i][j] = 1;
                } else {
                    vers0[i][j] = 1;
                }
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < szh; i++) {
        for (int j = i + 1; j < szh; j++) {
            ll b;
            if (szv < 1250) {

                b = (vers2[i] & vers2[j]).count();
            } else if (szv < 2500) {

                b = (vers1[i] & vers1[j]).count();;
            } else {

                b = (vers0[i] & vers0[j]).count();
            }
            ans += b * (b - 1) / 2;
        }
    }
    cout << ans << endl;
    return 0;
}