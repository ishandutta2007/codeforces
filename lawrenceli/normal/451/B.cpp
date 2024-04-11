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

int n, a[MAXN], b[MAXN];

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    rep(i, n) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b+n);
    rep(i, n) {
        if (a[i] != b[i]) {
            int j;
            for (j=n-1; j>=0 && a[j]==b[j]; j--);
            reverse(a+i, a+j+1);
            bool c=1;
            rep(k, n)
                if (a[k]!=b[k])
                    c = 0;
            if (c) {
                cout << "yes\n" << i+1 << ' ' << j+1 << '\n';
            } else cout << "no\n";
            return 0;
        }
    }
    cout << "yes\n1 1\n";
    return 0;
}