#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
 
#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) (((n % k) + k ) % k)

int n, t[105], d[105], p[105], e[105];
vvi dp(105, vi(2005, -1));

int obtRes (int i, int j) {
    if (i == n)
        return 0;

    if (dp[i][j] != -1) 
        return dp[i][j];

    int u = e[i];
    int res = obtRes(i+1, j);

    if (t[u] + j < d[u] && res < p[u] + obtRes(i+1, t[u]+j))
        res = p[u] + obtRes(i+1, t[u]+j);

    return dp[i][j] = res;
}

void recon () {
    int i = 0, j = 0, u;
    vi v;

    while (i < n) {
        u = e[i];
        if (t[u] + j < d[u] && dp[i][j] == obtRes(i+1, j+t[u]) + p[u]) {
            v.push_back(u+1);
            j += t[u];
        }

        i++;
    }

    cout << v.size() << endl;
    for (int x : v)
        cout << x << " ";
    cout << endl;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> d[i] >> p[i];
        e[i] = i;
    }

    sort(e, e+n, [](int a, int b) {return d[a] < d[b];});

    cout << obtRes (0, 0) << endl;
    recon();

    return 0;
}