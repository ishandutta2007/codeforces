
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

// consider a starting node as the root.
// how many ways to place casinos so that each leaf has even number of casinos along the way?
// we can place casinos arbitrarily for non-leaves, then leaves are dependent.
// if root is not leaf, 2^(N - num leaves)
// if root is leaf, 2^(N - num leaves + 1)

// (N - L) 2^(N - L) + L 2^(N - L + 1)

const int N = 1e5 + 5, M = 1e9 + 7;
int n, a, b, deg[N];
ll pow2[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n - 1) {
        cin >> a >> b;
        deg[a]++;
        deg[b]++;
    }
    if(n == 1) {
        cout << "1\n";
        return 0;
    }
    int L = 0;
    pow2[0] = 1;
    rep(i, 1, n + 1) {
        L += (deg[i] == 1);
        pow2[i] = (2 * pow2[i - 1]) % M;
    }
    ll ans = ((n - L) * pow2[n - L] + L * pow2[n - L + 1]) % M;
    cout << ans << '\n';
}