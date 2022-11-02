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

const int MAXN = 1005;
const int MAXK = 1000100;
const ll INF = 1e15;

int n, m, k, p, mat[MAXN][MAXN];
ll sumr[MAXK], sumc[MAXK];
priority_queue<ll> pq;

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m >> k >> p;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin >> mat[i][j];

    for (int i=0; i<n; i++) {
        ll sum = 0;
        for (int j=0; j<m; j++) sum += mat[i][j];
        pq.push(sum);
    }
    for (int i=1; i<=k; i++) {
        ll x = pq.top(); pq.pop();
        sumr[i] = sumr[i-1]+x;
        pq.push(x-p*m);
    }

    while (!pq.empty()) pq.pop();
    for (int j=0; j<m; j++) {
        ll sum = 0;
        for (int i=0; i<n; i++) sum += mat[i][j];
        pq.push(sum);
    }
    for (int i=1; i<=k; i++) {
        ll x = pq.top(); pq.pop();
        sumc[i] = sumc[i-1]+x;
        pq.push(x-p*n);
    }
/*
    for (int i=1; i<=k; i++) cout << sumr[i] << ' ';
    cout << endl;
    for (int i=1; i<=k; i++) cout << sumc[i] << ' ';
    cout << endl;
*/
    ll ans = -INF;
    for (int i=0; i<=k; i++)
        ans = max(ans, sumr[i]+sumc[k-i]-ll(k-i)*i*p);
    cout << ans << '\n';
    return 0;
}