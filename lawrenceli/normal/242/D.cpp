#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ios>

using namespace std;

const int MAXN = 100100;

int n, m, a[MAXN], b[MAXN];
vector<int> adj[MAXN];
vector<int> bad, ans;

int main() {
    ios :: sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (!a[i]) bad.push_back(i);
    }
    while (!bad.empty()) {
        int x = bad.back(); bad.pop_back();
        if (a[x] != b[x]) continue;
        ans.push_back(x);
        b[x]++;
        for (int i=0; i<adj[x].size(); i++) {
            int y = adj[x][i];
            b[y]++;
            if (b[y] == a[y]) bad.push_back(y);
        }
    }
    cout << ans.size() << '\n';
    for (int i=0; i<ans.size(); i++)
        cout << ans[i]+1 << ' ';
    return 0;
}