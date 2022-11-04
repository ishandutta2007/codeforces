#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 5005;
int n, k, x, a[MX];
ll dp[MX][MX];

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> k >> x;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if ((x + 1) * k - 1 < n) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 1; i <= x; i++) {
        deque<ii> q;

        for (int j = 0; j < min(n, i*k); j++) {
            if (q.empty()) dp[i][j] = a[j];
            else {
                while (q.size() && q.front().se < j - k)
                    q.pop_front();
                dp[i][j] = a[j] + q.front().fi;
            }

            while (q.size() && q.back().fi < dp[i-1][j])
                q.pop_back();
            q.emplace_back(dp[i-1][j], j);
        }
    }

    ll res = 0;
    for (int i = n - k; i < n; i++)
        res = max(res, dp[x][i]);
    cout << res << endl;

    return 0;
}