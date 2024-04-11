#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define px real()
#define py imag()
#define rep(i, n) for (int i=0, _##i=(n); i<_##i; ++i)
#define repi(i, n) for (__typeof((n).begin()) i=(n).begin(), _##i=n.end(); i != _##i; ++i)
#define sz(x) int((x).size())
#define print(x) cerr << #x << ": " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> pnt;

const int MAXN = 100100;

int n, nim[MAXN];

int calc(int x) {
    int& ret = nim[x];
    if (ret != -1) return ret;
    set<int> st;
    for (int k=1; k*(k+1)/2<x; k++) {
        int y = x-k*(k+1)/2;
        if (y%(k+1)) continue;
        y /= k+1;
        int res = 0;
        rep(i, k+1) res ^= calc(y+i);
        st.insert(res);
    }
    for (int i=0; 1; i++)
        if (!st.count(i))
            return ret = i;
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    memset(nim, -1, sizeof(nim));
    nim[0] = 0;
    for (int k=1; k*(k+1)/2<n; k++) {
        int y = n-k*(k+1)/2;
        if (y%(k+1)) continue;
        y /= k+1;
        int res = 0;
        rep(i, k+1) res ^= calc(y+i);
        if (!res) {
            cout << k+1;
            return 0;
        }
    }
    cout << "-1";
    return 0;
}