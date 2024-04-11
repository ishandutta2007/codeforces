#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 100 * 1000 + 10;
const int B = 1000;

vector<int> g[N];
int back[N];
int n, m, q;
vector<int> r_l[N];
vector<int> id_l[N];
int ans[N];
int f[N];
int dp[N];

void put(int i, int v) {
    for (; i < n; i = (i | (i + 1)))
        f[i] = max(f[i], v);
}

int get(int i) {
    int res = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1)
        res = max(res, f[i]);
    return res;
}

int solve_slow(int l, int r) {
    int res = l;
    for (int i = l + 1; i <= r; i++)
        if (back[i] >= l && back[i] <= res)
            res = i;
    return res;
}

void calc(int r) {
    fill(f, f + N, 0); 
    for (int l = r; l >= 0; l--) {
        dp[l] = l;
        int max_to = l;
        for (int to : g[l]) {
            if (to > r)
                continue;
            max_to = max(max_to, to);
        }
        dp[l] = max(dp[l], get(max_to));
        put(l, dp[l]);
    }
    for (int l = 0; l <= r; l++) {
        for (int i = 0; i < (int)r_l[l].size(); i++) {
            int qr = r_l[l][i];
            int id = id_l[l][i];
            if (ans[id] != -1)
                continue;
            if (qr < r)
                continue;
            ans[id] = dp[l];
            for (int p = r + 1; p <= qr; p++)
                if (back[p] >= l && back[p] <= ans[id])
                    ans[id] = p;
            ans[id]++;
        }
    }
}
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> m;
    fill(back, back + n, -1);
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        g[l].push_back(r);
        back[r] = l;
    }
    cin >> q;
    fill(ans, ans + q, -1);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        r_l[l].push_back(r);
        id_l[l].push_back(i);
        if (r - l <= B)
            ans[i] = solve_slow(l, r) + 1;
    }
    for (int r = (n - 1) / B * B; r >= 0; r -= B)
        calc(r);
    for (int i = 0; i < q; i++)
        cout << ans[i] << "\n";
}