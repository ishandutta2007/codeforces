#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 111;
const int K = 25;
const ll MOD = 1000 * 1000 * 1000 + 7;

ll dp[N][K][K]; // root, furthest, best black
vector<int> g[N];
int k;

void calc(int v, int par) {
    vector<int> kids;
    for (int to : g[v])
        if (to != par)
            kids.push_back(to);
    vector<vector<ll>> f(K, vector<ll>(K, 0));
    vector<vector<ll>> new_f(f);
    f[0][1] = 1; // make v black
    f[1][k + 3] = 1; // make v white
    for (int to : kids) {
        calc(to, v);
        for (int i = 0; i < K; i++)
            for (int j = 0; j < K; j++)
                new_f[i][j] = 0;
        for (int b = 0; b <= k + 3; b++)        
            for (int w = 0; w <= k + 3; w++)
                for (int new_b = 0; new_b <= k + 3; new_b++)
                    for (int new_w = 0; new_w <= k + 3; new_w++) {
                        int tb = new_b + 1;
                        int tw = new_w == 0 ? 0 : new_w + 1;
                        tb = min(tb, b);
                        tw = max(tw, w);
                        new_f[tw][tb] = (new_f[tw][tb] + f[w][b] * dp[to][new_w][new_b]) % MOD;
                                       
                    } 
        for (int i = 0; i < K; i++)
            for (int j = 0; j < K; j++)
                f[i][j] = new_f[i][j];
    }
    for (int white = 0; white <= k + 3; white++)
        for (int black = 0; black <= k + 3; black++) {
            int new_w = white;
            int new_b = black;
            if (black + white <= k + 2) 
                new_w = 0;
            dp[v][new_w][new_b] += f[white][black];    
            dp[v][new_w][new_b] %= MOD;    
        }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    calc(0, 0);    
    ll res = 0;
    for (int i = 0; i < K; i++) {
        res += dp[0][0][i];
        res %= MOD;
    }
    cout << res << endl; 
}