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

vector<int> a[MAX_N];

int n, m;

bool used[MAX_N];
long long cnt, sum;


void dfs(int v){
    sum += a[v].size();
    used[v] = true;
    cnt++;
    for (int u : a[v]) {
        if (!used[u]) {
            dfs(u);
        }
    }
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            cnt = sum = 0;
            dfs(i);
            if (cnt * (cnt - 1) != sum) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout <<"YES\n";
    return 0;
}