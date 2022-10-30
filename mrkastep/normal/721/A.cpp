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
    int n;
    string s;
    cin >> n >> s;
    vector<int> ans;
    for (int i = 0; i < s.size(); ++i) {
        while (i < s.size() && s[i] == 'W')
            ++i;
        if (i == s.size())
            break;
        int a = 0;
        while (i < s.size() && s[i] == 'B') {
            ++a;
            ++i;
        }
        ans.pb(a);
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ' ';
    }
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