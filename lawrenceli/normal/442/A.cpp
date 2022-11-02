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

int n;
string blah = "RGBYW";
int a[MAXN], b[MAXN];
bool ok[MAXN];
set<int> st1[5], st2[5];

bool good(int x, int y) {
    int cnt = 0;
    memset(ok, 0, sizeof(ok));
    for (int i=0; i<5; i++)
        st1[i].clear(), st2[i].clear();
    for (int i=0; i<n; i++)
        st1[a[i]].insert(b[i]), st2[b[i]].insert(a[i]);
    for (int i=0; i<n; i++)
        if ((1<<a[i]&x) && (1<<b[i]&y))
            cnt++, ok[i] = 1, st1[a[i]].erase(b[i]), st2[b[i]].erase(a[i]);
    while (cnt < n) {
        bool z = 0;
        int num = 0, num2 = 0;
        for (int i=0; i<5; i++) {
            if (st1[i].size() >= 1) num++;
            if (st1[i].size() == 1 && (1<<i&x)) {
                z = 1;
                for (int j=0; j<n; j++)
                    if (a[j] == i && !ok[j])
                        cnt++, ok[j] = 1, st1[a[j]].erase(b[j]), st2[b[j]].erase(a[j]);
            }
        }
        for (int i=0; i<5; i++) {
            if (st2[i].size() >= 1) num2++;
            if (st2[i].size() == 1 && (1<<i&y)) {
                z = 1;
                for (int j=0; j<n; j++)
                    if (b[j] == i && !ok[j])
                        cnt++, ok[j] = 1, st1[a[j]].erase(b[j]), st2[b[j]].erase(a[j]);
            }
        }
        if (num == 1 && num2 == 1) return 1;
        if (!z) return 0;
    }
    return 1;
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) {
        string s; cin >> s;
        char c = s[0];
        for (int j=0; j<5; j++)
            if (c == blah[j])
                a[i] = j;
        b[i] = s[1]-'0'-1;
    }

    int ans = 10;
    for (int i=0; i<1<<5; i++)
        for (int j=0; j<1<<5; j++) {
            int res = __builtin_popcount(i) + __builtin_popcount(j);
            if (good(i, j)) {
                ans = min(ans, res);
            }
        }
    cout << ans << '\n';
    return 0;
}