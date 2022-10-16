#include <bits/stdc++.h>

using namespace std;

//#define endl '\n'

typedef long long int64;
typedef pair<int64,int64> pii;
typedef vector<int> vi;

const int64 oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 1;

int deg[25], pnt = 0;
int dp[12][1 << 12][12];
int sm[1 << 12];

int solve(int node, int mask, int leaf){
    if (node == 0){
        return leaf > 1 && deg[node] == leaf + 1;
    }

    int &ans = dp[node][mask][leaf];
    if (ans != -1) return ans;
    ans = 0;

    for (int m = mask; m >= 0 && !ans; m = m == 0 ? -1 : (m - 1) & mask){
        int need = deg[node] - sm[m] - 1;

        if (need < 0 || need > leaf) continue;
        if (__builtin_popcount(m) + need == 1) continue;

        ans |= solve(node - 1, mask ^ m, leaf - need);
    }


    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int ones = 0;

    for (int i = 0; i < n; ++i){
        int d; cin >> d;

        if (d == 1)
            ones++;
        else
            deg[pnt++] = d;
    }

    if (ones <= pnt){
        cout << "NO" << endl;
        return 0;
    }

    sort(deg, deg + pnt);

    for (int i = 1; i < (1 << pnt); ++i){
        int u = __lg(i);
        sm[i] = deg[u] + sm[i ^ (1 << u)];
    }

    memset(dp, -1, sizeof dp);

    cout << (solve(pnt - 1, (1 << (pnt - 1) ) - 1, ones) ? "YES" : "NO") << endl;

    return 0;
}