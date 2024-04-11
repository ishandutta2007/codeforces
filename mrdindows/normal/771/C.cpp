//
//  main.cpp
//  acm
//
//  Created by Roman Rubanenko on 12/27/16.
//  Copyright  2016 Roman Rubanenko. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <memory.h>
#include <unordered_map>

using namespace std;


const int MAX_N = 200333;
const int MAX_K = 6;
vector<int> a[MAX_N];


pair<long long, long long> f[MAX_N][MAX_K];
int n, k;

pair<long long, long long> g[MAX_K];
long long ans = 0;

void dfs(int v, int p = 0) {
    for (int u : a[v]) {
        if (u == p) {
            continue;
        }
        dfs(u, v);
        for (int i = 0; i < k; i++) {
            auto& cur = f[v][(i + 1) % k];
            cur = {cur.first + f[u][i].first, cur.second + f[u][i].second + (i + 1 == k ? f[u][i].first : 0) };
        }
    }
    for (int i = 0; i < k; i++) {
        g[i] = {0, 0};
    }
    g[0] = {1, 0};
    for (int u : a[v]) {
        if (u == p) continue;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                ans += g[i].first * f[u][j].second + f[u][j].first * g[i].second;
                if (i + j + 1 <= k) {
                    ans += g[i].first * f[u][j].first;
                } else {
                    ans += g[i].first * f[u][j].first * 2;
                }
            }
        }
        for (int i = 0; i < k; i++) {
            g[(i + 1) % k] = {g[(i + 1) % k].first + f[u][i].first, g[(i + 1) % k].second + f[u][i].second + (i + 1 == k ? f[u][i].first : 0)};
        }
    }
    f[v][0].first++;
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n - 1; i++) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1);
    cout << ans << '\n';
    return 0;
}