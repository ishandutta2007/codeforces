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

const int MAXN = 100100;

int n, ar[MAXN], st[MAXN], nd[MAXN];

int main() { _
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) cin >> ar[i];

    st[0] = 0;
    for (int i=1; i<n; i++)
        if (ar[i] > ar[i-1]) st[i] = st[i-1];
        else st[i] = i;

    nd[n-1] = n;
    for (int i=n-2; i>=0; i--)
        if (ar[i] < ar[i+1]) nd[i] = nd[i+1];
        else nd[i] = i+1;

    int ans = 0;
    for (int i=0; i<n; i++) ans = max(ans, nd[i]-i);
    ans = min(n, ans+1);

    for (int i=1; i+1<n; i++)
        if (ar[i-1]+1 < ar[i+1])
            ans = max(ans, nd[i+1]-st[i-1]);

    cout << ans << '\n';
    return 0;
}