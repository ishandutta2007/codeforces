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
const int MOD = 1e9 + 7;

int u[MAXN], p[MAXN], fact[MAXN], inv[MAXN], fact2[MAXN];
vector<int> vdiv[MAXN];

int exp(int b, int e) {
    if (!e) return 1;
    int res = exp(b, e/2);
    if (e&1) return ll(res)*res%MOD*b%MOD;
    return ll(res)*res%MOD;
}

int C(int n, int k) {
    if (n < k) return 0;
    return ll(fact[n])*fact2[k]%MOD*fact2[n-k]%MOD;
}

void init() {
    fact[0] = fact2[0] = 1;
    for (int i=1; i<MAXN; i++) fact[i] = ll(fact[i-1])*i%MOD;
    for (int i=1; i<MAXN; i++) inv[i] = exp(i, MOD-2);
    for (int i=1; i<MAXN; i++) fact2[i] = ll(fact2[i-1])*inv[i]%MOD;
    for (int i=1; i<MAXN; i++) u[i] = p[i] = 1;
    p[1] = 0;
    for (int i=1; i<MAXN; i++) {
        for (int j=i; j<MAXN; j+=i) vdiv[j].push_back(i);
        if (p[i]) {
            if (ll(i)*i<MAXN) u[i*i] = 0;
            for (int j=i; j<MAXN; j+=i)
                p[j] = 0, u[j] *= -1;
        }
        if (!u[i])
            for (int j=i; j<MAXN; j+=i)
                u[j] = 0;
    }
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    init();
    int q; cin >> q;
    for (int i=0; i<q; i++) {
        int n, f;
        cin >> n >> f;
        int ans = 0;
        for (int j=0; j<vdiv[n].size(); j++) {
            int k = vdiv[n][j];
            ans = (ans+(u[k]*C(n/k-1, f-1)+MOD)%MOD)%MOD;
        }
        cout << ans << '\n';
    }
    return 0;
}