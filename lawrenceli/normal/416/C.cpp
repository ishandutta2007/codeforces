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

const int MAXN = 1005;

typedef pair<pii, int> piii;

int n;
piii arr[MAXN];
int k;
pii r[MAXN];
int occ[MAXN];
int m, s;

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> arr[i].fi.fi >> arr[i].fi.se;
        arr[i].se = i+1;
    }
    sort(arr, arr + n);
    reverse(arr, arr + n);

    cin >> k;
    for (int i=0; i<k; i++) {
        cin >> r[i].fi;
        r[i].se = i+1;
    }
    sort(r, r + k);

    memset(occ, -1, sizeof(occ));
    for (int i=0; i<n; i++) {
        bool good = 0;
        for (int j=0; j<k; j++)
            if (occ[j] == -1 && arr[i].fi.fi <= r[j].fi) {
                occ[j] = i;
                good = 1;
                m++;
                s += arr[i].fi.se;
                break;
            }
        if (good) continue;
        int repl = -1;
        for (int j=0; j<k; j++)
            if (occ[j] != -1)
                if (repl == -1 || arr[occ[j]].fi.se < arr[occ[repl]].fi.se)
                    repl = j;
        if (repl != -1 && arr[i].fi.se > arr[occ[repl]].fi.se) {
            s += arr[i].fi.se - arr[occ[repl]].fi.se;
            occ[repl] = i;
        }
    }

    cout << m << ' ' << s << '\n';
    for (int i=0; i<k; i++)
        if (occ[i] != -1)
            cout << arr[occ[i]].se << ' ' << r[i].se << '\n';
    return 0;
}