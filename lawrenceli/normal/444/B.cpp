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

int n, d, sqn, a[MAXN], b[MAXN], c[MAXN], ind[MAXN], par[MAXN], cnt;
ll x;

int getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return x;
}

void initAB() {
    int i;
    for(i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}

bool cmp(int x, int y) { return a[x] < a[y]; }

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> d >> x;
    sqn = sqrt(n);
    initAB();
    par[n] = n;
    for (int i=n-1; i>=0; i--)
        if (b[i]) par[i] = i;
        else par[i] = par[i+1];
    for (int i=0; i<sqn; i++) {
        for (int j=0; j<=i; j++)
            c[i] = max(c[i], a[j]*b[i-j]);
        cnt++;
    }
    for (int i=0; i<n; i++) ind[i] = i;
    sort(ind, ind+n, cmp);
    for (int ii=n-1; ii>=0 && cnt<n; ii--) {
        int j = ind[ii];
        for (int i=par[0]; i+j<n; i=par[i+1]) {
            if (!c[i+j])
                c[i+j] = a[j], cnt++;
        }
    }
    for (int i=0; i<n; i++)
        cout << c[i] << '\n';
    return 0;
}