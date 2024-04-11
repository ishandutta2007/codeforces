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
#define px real()
#define py imag()
#define rep(i, n) for (int i=0, _##i=(n); i<_##i; ++i)
#define dwn(i, n) for (int i=(n); --i>=0; )
#define repr(i, l, r) for (int i=(l), _##i=(r); i<_##i; ++i)
#define dwnr(i, l, r) for (int i=(r), _##i=(l); --i>=_##i; )
#define repi(i, n) for (__typeof((n).begin()) i=(n).begin(), _##i=n.end(); i != _##i; ++i)
#define dwni(i, n) for (__typeof((n).rbegin()) i=(n).rbegin(), _##i=(n).rend(); i!=_##i; ++i)
#define repv(i, n) for (int i=0, _##i=((n).size()); i<_##i; ++i)
#define dwnv(i, n) for (int i=((n).size()); --i>=0; )
#define sz(x) int((x).size())
#define print(x) cerr << #x << ": " << x << endl

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> pnt;
typedef vector<int> vi;

template <class T> T min(T a, T b, T c) { return min(a, min(b, c)); }
template <class T> T max(T a, T b, T c) { return max(a, max(b, c)); }
template <class T> void setmin(T& a, T b) { if (b < a) a = b; }
template <class T> void setmax(T& a, T b) { if (b > a) a = b; }

const int MAXN = 300100;

int n, w, a[MAXN], b[MAXN], num[MAXN];

typedef long long ll;
typedef pair<int, pii> piii;
piii ar[2*MAXN];
int cnt;

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> w;
    for (int i=0; i<n; i++) {
        cin >> a[i] >> b[i];
        if (2*a[i] < b[i]) {
            ar[cnt++] = piii(2*a[i], pii(i, 1));
            ar[cnt++] = piii(2*(b[i]-a[i]), pii(i, 1));
        } else ar[cnt++] = piii(b[i], pii(i, 2));
    }

    sort(ar, ar+cnt);
    int v = 0;
    ll t = 0;
    for (int i=0; i<cnt; i++) {
        v += ar[i].se.se;
        if (ar[i].se.se == 1) t += ar[i].fi/2;
        else t += ar[i].fi;
        num[ar[i].se.fi] += ar[i].se.se;
        if (v >= w) break;
    }

    if (v == w) {
        cout << t << '\n';
        for (int i=0; i<n; i++) cout << num[i];
        return 0;
    }

    int x = 0, y = -1;
    for (int i=0; i<n; i++)
        if (num[i] == 1) {
            if (a[i] > x)
                x = a[i], y = i;
        } else if (num[i] == 2) {
            if (b[i]-a[i] > x)
                x = b[i]-a[i], y = i;
        }

    int x1 = 1e9, y1 = -1, z = 0, z1 = -1;
    for (int i=0; i<n; i++)
        if (num[i] == 2)
            if (b[i] > z)
                z = b[i], z1 = i;

    for (int i=0; i<n; i++)
        if (num[i] == 0) {
            if (a[i] < x1)
                x1 = a[i], y1 = i;
        } else if (num[i] == 1) {
            if (b[i]-a[i] < x1)
                x1 = b[i]-a[i], y1 = i;
        }

    if (z1 == -1 || y1 == -1 || x > z-x1)
        num[y]--, t -= x;
    else
        num[z1]-=2, num[y1]++, t -= z-x1;

    cout << t << '\n';
    for (int i=0; i<n; i++) cout << num[i];
    return 0;
}