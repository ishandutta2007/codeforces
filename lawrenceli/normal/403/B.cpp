#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define fi first
#define se second
#define rep(i, n) for (int i=0, _##i=(n); i<_##i; i++)
#define repi(i, n) for (__typeof(n.begin()) i=n.begin(), _##i = n.end(); i != _##i; i++)
#define repv(i, n) for (int i=0, _##i=((n).size()); i<_##i; i++)
#define print(x) cerr << #x << ": " << x << endl;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> pnt;
typedef vector<int> vi;

template <class T> T min(T a, T b, T c) { return min(a, min(b, c)); }
template <class T> T max(T a, T b, T c) { return max(a, max(b, c)); }
template <class T> void setmin(T& a, T b) { if (b < a) a = b; }
template <class T> void setmax(T& a, T b) { if (b > a) a = b; }

const int MAXN = 5005;
const int MAXV = 32000;

int n, m;
int a[MAXN], b[MAXN], dp[MAXN];
bool prime[MAXV];
set<int> bad;
vector<int> primes;

void init() {
    for (int i=2; i<MAXV; i++) prime[i] = 1;
    for (int i=2; i<MAXV; i++)
        if (prime[i]) {
            primes.push_back(i);
            for (int j=2*i; j<MAXV; j+=i)
                prime[j] = 0;
        }
}

int calc(int x) {
    int ret = 0;
    for (int i=0; i<primes.size() && x > 1; i++) {
        int v = bad.count(primes[i]) ? -1 : 1;
        while (x % primes[i] == 0) x /= primes[i], ret += v;
    }
    if (x > 1) ret += (bad.count(x) ? -1 : 1);
    return ret;
}

int gcd(int a, int b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(a, b % a);
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<m; i++) {
        cin >> b[i];
        bad.insert(b[i]);
    }

    init();

    int cur = 0;
    for (int i=0; i<n; i++) cur += calc(a[i]);
    for (int i=0; i<=n; i++) dp[i] = -1e9;
    dp[0] = cur;
    int g = 0;
    for (int i=0; i<n; i++) {
        g = gcd(g, a[i]);
        int c = calc(g);
        for (int j=0; j<=i; j++)
            setmax(dp[i+1], dp[j] - c * (i-j+1));
    }

    int ans = -1e9;
    for (int i=0; i<=n; i++) setmax(ans, dp[i]);

    cout << ans << '\n';
    return 0;
}