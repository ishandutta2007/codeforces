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

const int MAXN = 100100;

int n, k, p, a[MAXN];
vector<int> b[2];
vector<vector<int> > ans[2];
int p1, p2;

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> k >> p;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        b[a[i]%2].push_back(a[i]);
    }
    if ((b[1].size()%2) != (k-p)%2) {
        cout << "NO\n";
        return 0;
    }

    for (int i=0; i<min(p, int(b[0].size())); i++) {
        ans[0].push_back(vector<int>());
        ans[0].back().push_back(b[0][p1++]);
    }
    for (int i=0; i<min(k-p, int(b[1].size())); i++) {
        ans[1].push_back(vector<int>());
        ans[1].back().push_back(b[1][p2++]);
    }
    while (ans[0].size() < p) {
        if (p2 < b[1].size()-1) {
            ans[0].push_back(vector<int>());
            ans[0].back().push_back(b[1][p2++]);
            ans[0].back().push_back(b[1][p2++]);
        } else {
            cout << "NO\n";
            return 0;
        }
    }

    if (ans[1].size() < k-p) {
        cout << "NO\n";
        return 0;
    }

    for (; p1<b[0].size(); p1++) {
        if (!ans[0].empty()) ans[0][0].push_back(b[0][p1]);
        else ans[1][0].push_back(b[0][p1]);
    }
    for (; p2<b[1].size(); p2++) {
        if (!ans[0].empty()) ans[0][0].push_back(b[1][p2]);
        else ans[1][0].push_back(b[1][p2]);
    }

    cout << "YES\n";
    for (int i=0; i<2; i++)
        for (int j=0; j<ans[i].size(); j++) {
            cout << ans[i][j].size() << ' ';
            for (int k=0; k<ans[i][j].size(); k++)
                cout << ans[i][j][k] << ' ';
            cout << '\n';
        }
    return 0;
}