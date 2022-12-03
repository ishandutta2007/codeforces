#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>

const int N = 2e5 + 7;

using namespace std;

int n, m, s;
int pre[N];
int col[N];
int ans[N], cnt;
vector<int> v[N];

void dfs(int x, int c) {
    for (auto y : v[x]) {
        if (col[y] == c || y == s) continue;
        if (col[y]) {
            puts("Possible");
            for (int u = y; u; u = pre[u]) ans[++cnt] = u;
            cout << cnt << endl;
            for (int i = cnt; i; i--) printf("%d ", ans[i]);
            cout << endl;
            cnt = 0;
            for (int u = x; u; u = pre[u]) ans[++cnt] = u;
            cout << cnt + 1 << endl;
            for (int i = cnt; i; i--) printf("%d ", ans[i]);
            cout << y << endl;
            exit(0);
        }
        col[y] = c;
        pre[y] = x;
        dfs(y, c);
    }
}

int main() {
    cin >> n >> m >> s;
    while (m--) {
        int x, y;
        scanf("%d%d", &x, &y);
        v[x].push_back(y);
    }
    for (int i = 0; i < v[s].size(); i++) {
        int y = v[s][i];
        if (col[y]) {
            puts("Possible");
            for (int u = y; u; u = pre[u]) ans[++cnt] = u;
            cout << cnt << endl;
            for (int i = cnt; i; i--) printf("%d ", ans[i]);
            cout << endl << 2 << endl << s << ' ' << y << endl;
            exit(0);
        }
        pre[y] = s;
        col[y] = i + 1;
        dfs(y, i + 1);
    }
    puts("Impossible");
    return 0;
}