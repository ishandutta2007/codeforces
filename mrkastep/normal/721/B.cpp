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
const int MAXN = 200;

#define x first
#define y second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<double, double> point;

void solve() {
    vector<string> v;
    string p;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> p;
        v.pb(p);
    }
    cin >> p;
    sort(v.begin(), v.end(), [&](const string& s1, const string& s2) {return s1.size() < s2.size(); });
    int cnt = 0;
    int ans = 0;
    int i;
    for (i = 0; i < v.size() && v[i].size() < p.size(); ++i) {
        ++cnt;
        ++ans;
        if (cnt == k)
            ans += 5;
        cnt %= k;
    }
    cout << ans + 1 << ' ';
    for (; i < v.size() && v[i].size() == p.size(); ++i) {
        ++cnt;
        ++ans;
        if (cnt == k)
            ans += 5;
        cnt %= k;
    }
    if (cnt == 0) ans -= 5;
    cout << ans;
}

int main() {
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // _DEBUG
    solve();


    return 0;
}