#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 998244353;

int col[501];
int mn[501][501];
int ans[501][501];

int solve(int b, int e){
    if (e <= b) return 1;

    int &x = ans[b][e];
    if (x != -1) return x;

    int le = 0, ri = 0;

    int p = mn[b][e];

    assert(b <= p && p <= e);

    for (int i = b; i <= p; ++i){
        le += 1LL * solve(b, i - 1) * solve(i, p - 1) % mod;
        if (le >= mod) le -= mod;
    }

    for (int i = p; i <= e; ++i){
        ri += 1LL * solve(p + 1, i) * solve(i + 1, e) % mod;
        if (ri >= mod) ri -= mod;
    }

    x = 1LL * le * ri % mod;
    return x;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i){
        cin >> col[i];
    }

    for (int i = 0; i < n; ++i){
        int ix = i;

        for (int j = i; j < n; ++j){
            if (col[j] < col[ix])
                ix = j;
            mn[i][j] = ix;
        }
    }

    memset(ans, -1, sizeof ans);

    cout << solve(0, n - 1) << endl;

    return 0;
}