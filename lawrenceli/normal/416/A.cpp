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

const int INF = 1e9 + 5;

int n, l=-INF, r=INF;

void updl(int x) { l = max(l, x); }
void updr(int x) { r = min(r, x); }

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    rep(i, n) {
        string s;
        int x;
        char c;
        cin >> s >> x >> c;
        if (s == ">") s = ">=", x++;
        if (s == "<") s = "<=", x--;
        if (s == ">=") {
            if (c == 'Y') updl(x);
            else updr(x-1);
        } else {
            if (c == 'Y') updr(x);
            else updl(x+1);
        }
    }

    if (l > r) cout << "Impossible";
    else cout << l;
    return 0;
}