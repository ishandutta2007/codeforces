#include <stdio.h> 
#include <iostream> 
#include <vector> 
#include <cstdlib> 
#include <map> 
#include <time.h> 
#include <string> 
#include <algorithm> 
#include <queue> 
#include <assert.h> 
#include <math.h> 
#include <complex>
#include <set>


using namespace std;

const int INF = 2e9;
const int mod = 1e9 + 7;
const long long LONGINF = 4e18;
const double eps = 1e-9;
const double PI = 3.1415926535897932384626433832795;

#define x first
#define y second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<double, double> point;

map<ll, int> m;

int type() {
    char c;
    cin >> c;
    switch (c) {
    case '+': return 1;
    case '-': return 2;
    case '?': return 3;
    default: return 0;
    }
}

void solve() {
    int n;
    cin >> n;
    while (int t = type()) {
        ll a, s;
        if (t == 0) {
            return;
        }
        cin >> a;
        s = 0;
        int i = 0;
        while (a > 0) {
            s += a % 10 % 2 * (1ll << i++);
            a /= 10;
        }
        if (t == 1) {
            ++m[s];
        }
        if (t == 2) {
            --m[s];
        }
        if (t == 3) {
            cout << m[s] << endl;
        }
    }
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    solve();
    return 0;
}