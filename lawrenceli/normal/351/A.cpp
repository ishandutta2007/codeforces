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

const int MAXN = 5010;

int n, num;
double a[MAXN], sum, ans = 1e9;

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d", &n);
    for (int i=0; i<2*n; i++) scanf("%lf", &a[i]);
    for (int i=0; i<2*n; i++) {
        if (abs(a[i] - int(a[i])) < 1e-9) num++;
        sum += int(a[i]) - a[i];
    }
    print(sum); print(num);
    for (int i=0; i<=min(n, num); i++) {
        ans = min(ans, abs(sum + n - i));
    }
    printf("%.3lf\n", ans);
}