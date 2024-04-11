#include <stdio.h> 
#include <iostream> 
#include <vector> 
#include <cstdlib> 
#include <map> 
#include <unordered_map>
#include <unordered_set>
#include <time.h> 
#include <string> 
#include <algorithm> 
#include <queue> 
#include <assert.h> 
#include <math.h> 
#include <complex>
#include <set>
#include <cstring>


using namespace std;

const int INF = 2e9;
const int mod = 1e9 + 7;
const long long LONGINF = 4e18;
const double eps = 1e-9;
const double PI = 3.1415926535897932384626433832795;
const int MAXN = 200200;

#define x first
#define y second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef pair<double, double> point;

void solve() {
    int n;
    string s;
    scanf("%d", &n);
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.size() && s[i] == '<'; ++i, ++ans);
    for (int i = s.size() - 1; i >= 0 && s[i] == '>'; --i, ++ans);
    cout << ans;

}

int main() {
#pragma comment(linker,"/STACK:268435456")
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();

    return 0;
}