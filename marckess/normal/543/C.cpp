#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MX = (1 << 21);
int n, m, a[20][20], mk, dp[MX], p[MX];
int sum[256][20], mask[256][20];
string s[20];

void precal() {
    for (int i = 0; i < mk; i++)
        for (int j = 0; j < n; j++)
            if (!(i & (1 << j))) {
                p[i] = j;
                break;
            }

    for (int i = 'a'; i <= 'z'; i++) {
        for (int j = 0; j < m; j++) {
            int mx = 0;
            for (int k = 0; k < n; k++) {
                if (s[k][j] == char(i)) {
                    sum[i][j] += a[k][j];
                    mx = max(mx, a[k][j]);
                    mask[i][j] |= (1 << k);
                }
            }
            sum[i][j] -= mx;
        }
    }
}

int obtRes (int k) {
    int &res = dp[k], i = p[k];
    if (res != -1)
        return res;
    res = 1e9;

    for (int j = 0; j < m; j++)
        res = min( {res, obtRes(k | (1 << i)) + a[i][j], obtRes(k | mask[s[i][j]][j]) + sum[s[i][j]][j]} );
    return res;
} 

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    mk = (1 << n) - 1;

    for (int i = 0; i < n; i++)
        cin >> s[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    for (int i = 0; i < mk; i++)
        dp[i] = -1;
    dp[mk] = 0;

    precal();
    cout << obtRes(0) << endl;

    return 0;
}