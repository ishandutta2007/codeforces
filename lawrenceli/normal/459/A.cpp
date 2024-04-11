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

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int d1 = abs(x1-x2), d2 = abs(y1-y2);
    if (d1!=0 && d2!=0 && d1!=d2) {
        cout << -1;
        return 0;
    }
    if (d1==0) swap(d1, d2);

    int x3 = min(x1, x2), y3 = min(y1, y2);

    for (int i=0; i<2; i++)
        for (int j=0; j<2; j++) {
            int x4 = x3+i*d1, y4 = y3+j*d1;
            if ((x4 != x1 || y4 != y1) && (x4 != x2 || y4 != y2))
                cout << x4 << ' ' << y4 << ' ';
        }
    return 0;
}