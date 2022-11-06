
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

ll a[300500];
ll b[20050], used[1005];
set<ll> g[1005];
ll mex() {
    for (int j = 0; j <= n; j++) {
        b[j] = 0;
    }
    for (int i = 1; i <= n; i++) {
        b[a[i]] = 1;
    }
    for (int i = 0; i <= n; i++) {
        if (b[i] == 0) {
            return i;
        }
    }
}
void print() {

    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}
bool good() {
    for (int i = 2; i <= n; i++) {
        if (a[i] < a[i-1]) {
            return false;
        }
    }
    return true;
}
vector<ll> f;
vector<ll> ans;
vector<ll> tmp;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        ans.clear();
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            used[i] = 0;
        }
        ans.clear();
        if (!good()) {
            for (int i = 0; i < 2 * n; i++) {
                ll s = mex();
                ll p = s;
                if (s == 0 || used[s]) {
                    p = s + 1;
                }
                used[p] = 1;
                ans.push_back(p);
                a[p] = s;
                if (good()) {
                    break;
                }
            }
        }
        cout << ans.size() << "\n";
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
        //print();
        //print();
    }

    return 0;
}