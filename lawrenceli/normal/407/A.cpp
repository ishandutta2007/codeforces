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

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    int a, b;
    cin >> a >> b;
    vector<pii> v1, v2;
    for (int x=1; x<a; x++)
        for (int y=1; y<a; y++)
            if (x*x+y*y == a*a)
                v1.push_back(pii(x, y));
    for (int x=1; x<b; x++)
        for (int y=1; y<b; y++)
            if (x*x+y*y == b*b)
                v2.push_back(pii(x, y));

    for (int i=0; i<v1.size(); i++)
        for (int j=0; j<v2.size(); j++) {
            int x1 = v1[i].fi, y1 = v1[i].se, x2 = v2[j].fi, y2 = v2[j].se;
            if (x1 != x2 && x1*x2 == y1*y2) {
                cout << "YES\n";
                cout << "0 0\n";
                cout << x1 << ' ' << y1 << '\n';
                cout << x1-x2 << ' ' << y1+y2 << '\n';
                return 0;
            }
        }
    cout << "NO\n";
    return 0;
}