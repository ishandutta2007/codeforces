#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <cassert>
#include <stdlib.h>

using namespace std;



const int N = 111;
int q[N];
int cur[N];
int temp[N];
int rev[N];
int fin[N];
int n;
int k;
int cache[N][N];
bool used[N][N];
bool any = false;

bool fits(int cntQ, int cntRev) {
    if (cache[cntQ][cntRev] >= 0)
        return cache[cntQ][cntRev];
    for (int i = 0; i < n; ++i)
        cur[i] = i;
    for (int num = 0; num < cntQ; ++num) {
        for (int i = 0; i < n; ++i)
            temp[i] = cur[q[i]];
        for (int i = 0; i < n; ++i)
            cur[i] = temp[i];
    }
    for (int num = 0; num < cntRev; ++num) {
        for (int i = 0; i < n; ++i)
            temp[i] = cur[rev[i]];
        for (int i = 0; i < n; ++i)
            cur[i] = temp[i];
    }
    
    bool ok = true;
    for (int i = 0; i < n; ++i)
        if (cur[i] != fin[i])
            ok = false;
    
    if (ok)
        cache[cntQ][cntRev] = 1;
    else
        cache[cntQ][cntRev] = 0;
    return cache[cntQ][cntRev];
}

void dfs(int i, int j) {
    if (used[i][j])
        return;
    used[i][j] = true;
    if (cache[i][j] == 1) {
        if (i + j == k)
            any = true;
        return;
    }
    if (i + 1 <= k)
        dfs(i + 1, j);
    if (j + 1 <= k)
        dfs(i, j + 1);
}
    
    

int main() {
    ios_base::sync_with_stdio(false);
    
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> q[i];
    for (int i = 0; i < n; ++i)
        --q[i];
    for (int i = 0; i < n; ++i) 
        rev[q[i]] = i;
        
    for (int i = 0; i < n; ++i)
        cin >> fin[i];
    for (int i = 0; i < n; ++i)
        --fin[i];
    
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            used[i][j] = false;
            cache[i][j] = -1;
        }
    for (int i = 0; i <= k; ++i)
        for (int j = 0; j <= k; ++j)
            fits(i, j);
    
    dfs(0, 0);
    
    
    cout << (any ? "YES" : "NO");
    
    return 0;
}