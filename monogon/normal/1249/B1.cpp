
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int q, n;
int p[N];
bool vis[N];

int dfs(int x, int len) {
    if(vis[x]) return p[x] = len;
    vis[x] = true;
    return p[x] = dfs(p[x], len + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while(q--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> p[i];
            p[i]--;
        }
        fill(vis, vis + n, false);
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i, 0);
            }
            cout << p[i] << " ";
        }
        cout << endl;
    }
}