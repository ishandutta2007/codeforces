#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <complex>
#include <map>
#include <set>
#include <queue>

using namespace std;

typedef long long ll;

const int inf = 2e9;
const ll LONGINF = 8e18;
const int MAXN = 110;

int p[100100], cnt;

int fs(int v) {
    if(p[v] == v) return v;
    return p[v] = fs(p[v]);
}

void us(int a, int b) {
    a = fs(a);
    b = fs(b);
    if(a != b)
        --cnt;
    p[a] = b;
}

int a[100100], ind[100100];
vector<int> ans[100100];


void solve() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        p[i] = i;
        ind[i] = i;
    }
    cnt = n;
    sort(ind, ind + n, [&](int u, int v){return a[u] < a[v];});
    for(int i = 0; i < n; ++i)
        us(ind[i], i);
    for(int i = 0; i < n; ++i)
        ans[fs(i)].push_back(i);
    cout << cnt << endl;
    for(int i = 0; i < n; ++i) {
        if(!ans[i].empty()) {
            cout << ans[i].size();
            for(auto j : ans[i])
                cout << ' ' << j + 1;
            cout << endl;
        }
    }
}

int main() {
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}