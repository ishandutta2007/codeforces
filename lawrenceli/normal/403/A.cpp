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
#define rep(i, n) for (int i=0, _##i=(n); i<_##i; i++)
#define repi(i, n) for (__typeof(n.begin()) i=n.begin(), _##i = n.end(); i != _##i; i++)
#define repv(i, n) for (int i=0, _##i=((n).size()); i<_##i; i++)
#define print(x) cerr << #x << ": " << x << endl;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> pnt;
typedef vector<int> vi;

template <class T> T min(T a, T b, T c) { return min(a, min(b, c)); }
template <class T> T max(T a, T b, T c) { return max(a, max(b, c)); }
template <class T> void setmin(T& a, T b) { if (b < a) a = b; }
template <class T> void setmax(T& a, T b) { if (b > a) a = b; }

const int MAXN = 100;

int T, n, p;
vector<pii> ans;
bool mat[MAXN][MAXN];

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> T;
    for (int t=0; t<T; t++) {
        cin >> n >> p;
        int cnt = 2*n+p;
        ans.clear();
        memset(mat, 0, sizeof(mat));
        for (int i=0; i<n; i++) {
            if (!cnt) break;
            ans.push_back(pii(i, (i+1)%n));
            mat[i][(i+1)%n] = mat[(i+1)%n][i] = 1;
            cnt--;
            if (!cnt) break;
            ans.push_back(pii(i, (i+2)%n));
            mat[i][(i+2)%n] = mat[(i+2)%n][i] = 1;
            cnt--;
        }

        for (int i=0; i<n; i++)
            for (int j=i+1; j<n; j++)
                if (!mat[i][j] && cnt) {
                    ans.push_back(pii(i, j));
                    mat[i][j] = mat[j][i] = 1;
                    cnt--;
                }

        for (int i=0; i<ans.size(); i++)
            cout << ans[i].fi+1 << ' ' << ans[i].se+1 << '\n';
    }

    return 0;
}