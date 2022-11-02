#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define rep(i, n) for (int i=0, _##i=(n); i<_##i; i++)
#define repi(i, n) for (typeof(n.begin()) i=n.begin(), _##i = n.end(); i != _##i; i++)
#define repv(i, n) for (int i=0, _##i=((n).size()); i<_##i; i++)
#define print(x) cerr << #x << " is " << x << endl;

typedef long long ll;
typedef pair<int, int> pii;

template <class T> T min(T a, T b, T c) { return min(a, min(b, c)); }
template <class T> T max(T a, T b, T c) { return max(a, max(b, c)); }
template <class T> void setmin(T& a, T b) { if (b < a) a = b; }
template <class T> void setmax(T& a, T b) { if (b > a) a = b; }

const int MAXM = 20;
const int MAXN = 1100;

int n, m, c0, d0, a[MAXM], b[MAXM], c[MAXM], d[MAXM], dp[MAXN], ans;

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d %d %d %d", &n, &m, &c0, &d0);
    for (int i=0; i<m; i++) scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
    for (int i=0; i<=n/c0; i++) {
        setmax(dp[n-i*c0], i*d0);
    }
    for (int i=0; i<m; i++) {
        for (int j=0; j<=n; j++) {
            for (int k=0; k<=a[i]/b[i]; k++) {
                if (j+k*c[i] <= n)
                    setmax(dp[j], dp[j+k*c[i]] + k*d[i]);
            }
        }
    }
    for (int i=0; i<=n; i++) setmax(ans, dp[i]);
    printf("%d\n", ans);
}