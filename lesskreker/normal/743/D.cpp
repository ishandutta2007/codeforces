#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
}

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

typedef long long lint;

int a[222222];
vector<int> g[222222];
lint d[222222][2];
int cc[222222];
lint m1[222222];
lint m2[222222];

void dfs(int v, int p) {
    d[v][1] = a[v];
    d[v][0] = -1e18;
    m1[v] = -1e18;
    m2[v] = -1e18;
    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        cc[v]++;
        dfs(i, v);
        d[v][0] = max(d[v][0], max(d[i][0], d[i][1]));
        d[v][1] += d[i][1];
    }
    d[v][0] = max(d[v][0], d[v][1]);
    
    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        if (d[i][0] >= m1[v]) {
            m2[v] = m1[v];
            m1[v] = d[i][0];
        } else if (d[i][0] >= m2[v]) {
            m2[v] = d[i][0];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);  
    for (int i = 0; i < n; i++) {
        sci(a[i]);
    }
    
    for (int i = 1; i < n; i++) {
        scid(x, y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    dfs(0, -1);
    lint ans = -1e18;
    for (int i = 0; i < n; i++) {
        if (cc[i] > 1) {
            ans = max(ans, m1[i] + m2[i]);
        }
    }
    
    if (ans == -1e18) {
        cout << "Impossible";
    } else {
        cout << ans;
    }
    

    return 0;
}