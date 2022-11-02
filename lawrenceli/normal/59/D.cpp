#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define px real()
#define py imag()
#define repi(i, n) for (__typeof((n).begin()) i=(n).begin(), _##i=n.end(); i != _##i; ++i)
#define sz(x) int((x).size())
#define print(x) cerr << #x << ": " << x << endl
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> pnt;

const int MAXN = 300100;

int n, ar[MAXN], k;
pii adj[MAXN];
bool in[MAXN], in2[MAXN];

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<3*n; i++) cin >> ar[i];
    for (int i=0; i<n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a] = pii(b, c);
        adj[b] = pii(a, c);
        adj[c] = pii(a, b);
    }
    cin >> k;
    for (int i=0; i<3*n; i++) {
        int x = ar[i];
        if (in[x]) {
            if (x == k) {
                for (int j=1; j<=3*n; j++)
                    if (j!=k)
                        cout << j << ' ';
            }
            in[x] = 1;
        } else {
            if (x == k) {
                int cnt = 0;
                for (int j=1; j<=3*n; j++)
                    if (j!=k)
                        if (in[j]) in2[j] = 1, cout << j << ' ';
                        else if (j == adj[x].fi || j == adj[x].se) {
                            in2[j] = 1, cout << j << ' ';
                            cnt++;
                            if (cnt == 2) break;
                        }
                for (int j=1; j<=3*n; j++)
                    if (j!=k)
                        if (!in2[j])
                            cout << j << ' ';
            }
            in[x] = 1;
            in[adj[x].fi] = 1;
            in[adj[x].se] = 1;
        }
    }
    return 0;
}