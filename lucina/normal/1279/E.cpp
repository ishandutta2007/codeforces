#include<bits/stdc++.h>
using namespace std;
int const nax = 53;
using ll = long long ;
ll const inf = 1e18;
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
 
ll add (ll x, ll y) {
    return min(inf, x + y);
}
 
ll mul (ll x, ll y) {
    if (x >= inf / y) return inf;
    return min(inf, x * y);
}
 
int pa[53];
ll f[53];
ll dp[53];
 
int find (int x) {
    return pa[x] == x ? x : pa[x] = find(pa[x]);
}
 
 
 
 
vector<int> gen_cycle (int n, ll k) {
 
    // eprintf("gen cycle %d %lld\n", n, k);
    vector<int> res(n);
    res[0] = n;
    iota(pa + 1, pa + 1 + n, 1);
    set<int> used;
    used.insert(n);
 
    pa[find(n)] = find(1);
 
    for (int i = 1 ; i < n ; ++ i) {
 
        for (int t = 1 ; t < n ; ++ t) {
            if (!used.count(t) && ((find(i + 1) != find(t)) || i == n - 1)) {
                ll w = n >= i + 2 ? f[n - i - 2] : 1;
                if (w <= k) {
                    k -= w;
                    continue;
                }
                used.insert(t);
                res[i] = t;
                pa[find(t)] = find(i + 1);
                break;
            }
        }
    }
 
    // eprintf("reach\n");
 
    return res;
 
}
 
 
vector<int> solve (int n, ll k) {
 
   // eprintf("solve huh %d %lld\n", n, k);
 
    if (k == 0) {
        vector<int> stp(n);
        iota(stp.begin(), stp.end(), 1);
        return stp;
    }
 
    for (int i = 1 ; i <= n;  ++ i) {
        ll x = mul(i == 1 ? 1 : f[i - 2], dp[n - i]);
 
        if (x <= k) {
            k -= x;
            continue;
        }
 
        vector<int> cyc = gen_cycle(i, k / dp[n - i]);
        vector<int> ret = solve(n - i, k % dp[n - i]);
 
        for (int j : ret) cyc.push_back(i + j);
 
        //assert(cyc.size() == n);
 
        return cyc;
 
    }
 
    return vector<int>();
}
 
 
 
int main(){
    int T;
 
    int n;
    ll k;
 
    f[0] = 1;
    for (int i = 1 ; i <= 51 ; ++ i)
        f[i] = mul(f[i - 1], i);
 
    dp[0] = dp[1] = 1;
    for (int i = 2 ; i <= 51 ; ++ i) {
        dp[i] = dp[i - 1];
 
        for (int j = 2 ; j <= i ; ++ j)
            dp[i] = add(dp[i], mul(f[j - 2], dp[i - j]));
    }
 
 
 
    for(scanf("%d", &T) ; T -- ;){
        scanf("%d %lld", &n, &k);
 
        if (dp[n] < k) {
            printf("-1\n");
            continue;
        }
 
        -- k;
 
 
 
        vector<int> ans = solve(n, k);
 
        for (int i : ans) {
            printf("%d ", i);
        }
 
        printf("\n");
 
    }
}
/**
    Good Luck
        -Lucina
*/