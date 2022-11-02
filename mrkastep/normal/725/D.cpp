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

pair <ll, ll> t[300300];
ll T[1 << 20], C[1 << 20];
int ind[300300], ind1[300300];

void add(int v, int l, int r, int pos, ll val) {
    if (l + 1 == r) {
        T[v] = val;
        C[v] = 1;
        return;
    }
    int m = (l + r) / 2;
    if (pos < m)
        add(2 * v, l, m, pos, val);
    else
        add(2 * v + 1, m, r, pos, val);
    T[v] = min(LONGINF, T[2 * v] + T[2 * v + 1]);
    C[v] = C[2 * v] + C[2 * v + 1];
}

int ask(int v, int l, int r, ll sum) {
    if (l + 1 == r) {
        return C[v] * (T[v] <= sum);
    }
    int m = (l + r) / 2;
    if (T[2 * v] >= sum)
        return ask(2 * v, l, m, sum);
    else
        return C[2 * v] + ask(2 * v + 1, m, r, sum - T[2 * v]);
}

bool cmp(int a, int b) {
    return t[a].y - t[a].x < t[b].y - t[b].x;
}

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < (1 << 20); ++i)
        T[i] = C[i] = 0;
    for (int i = 0; i < n; ++i)
        scanf("%lld%lld", &t[i].x, &t[i].y);
    sort(t + 1, t + n);
    reverse(t + 1, t + n);
    for (int i = 0; i < n; ++i) {
        ind1[i] = i;
    }
    sort(ind1, ind1 + n, cmp);
    for (int i = 0; i < n; ++i)
        ind[ind1[i]] = i;
    ll give = 0;
    int ans = n;
    for (int i = 1; i < n; ++i) {
        if (t[i].x <= t[0].x) {
            ans = i;
            give = t[0].x - t[i].x;
            break;
        }
    }
    for (int i = 1; i < n; ++i) {
        if (t[i].x <= t[0].x) {
            int k = ask(1, 0, n, give);
            ans = min(ans, i - k);
            give = t[0].x - (i == n - 1 ? 0 : t[i + 1].x);
        }
        add(1, 0, n, ind[i], t[i].y - t[i].x + 1);
    }
    give = t[0].x;
    int k = ask(1, 0, n, give);
    ans = min(ans, n - k);
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