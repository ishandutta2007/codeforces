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

const int INF = 1e9;

string a;
int k;

int num(int p, int x) {
    for (int i=p; i<a.length(); i++)
        if (a[i] == x+'0')
            return i-p;
    return INF;
}

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> a >> k;
    rep(i, a.length()) {
        for (int j=9; j>=0; j--)
            if (num(i, j) <= k) {
                int res = num(i, j);
                k -= res;
                for (int i1=res+i; i1>i; i1--)
                    swap(a[i1-1], a[i1]);
                break;
            }
    }
    cout << a << '\n';
    return 0;
}