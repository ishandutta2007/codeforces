#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdio.h>

using namespace std;

#define mp make_pair
#define vec vector
#define ALL(x) (x).begin(), (x).end() 

typedef long long ll;
typedef long double ld;

bool lucky(int x) {
    while(x) {
        if(x % 10 != 4 && x % 10 != 7) return 0;
        x /= 10;
    }
    return 1;
}

int n;
vec< pair< int, int> > e;

vec< int > par, size, cnt;
vec< ll > dp;

int find(int x) {
    return (x == par[x]?x : par[x] = find(par[x]));
}

void merge(int x, int y, ll value) {
    int px = find(x);
    int py = find(y);
    if(size[px] == size[py]) {
        par[py] = px;
        size[px]++;
        cnt[px] += cnt[py];
        dp[px] = value;
    }else {
        if(size[px] < size[py]) swap(px, py);
        par[py] = px;
        cnt[px] += cnt[py];
        dp[px] = value;
    }
}

void read() {

    scanf("%d", &n);

    par.resize(n + 1);
    size.resize(n + 1, 1);
    cnt.resize(n + 1, 1);
    dp.resize(n + 1);

    for(int i = 1;i <= n;i++) {
        par[i] = i;
    }

    for(int u, v, w, i = 0;i < n - 1;i++) {
        scanf("%d %d %d", &u, &v, &w);
        if(lucky(w)) {
            e.push_back(mp(u, v));
        }else {
            if(find(u) != find(v)) {
                merge(u, v, 0);
            }
        }
    }
}

bool solve() {
    
    read();

    ll ans = 0;

    for(int i = 0;i < (int)e.size();i++) {
        int u, v, pu, pv;
        u = e[i].first;
        v = e[i].second;
        if(find(u) == find(v)) continue;
        pu = find(u);
        pv = find(v);
        ll A, B;
        A = cnt[pu];
        B = cnt[pv];
        
        ans += A * B * (B - 1);
        ans += dp[pu] * B * 2;
        ans += B * A * (A - 1);
        ans += dp[pv] * A * 2;

        merge(u, v, 2ll * A * B + dp[pu] + dp[pv]);

    }

    cout << ans << '\n';

    return 0;
}

int main() {
    
    //while(solve());
    solve();

    return 0;
}