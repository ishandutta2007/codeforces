#include <bits/stdc++.h>

using namespace std;

const int MAXN = 205;
const int MAX = 20010;

int n, a[MAXN], b[MAXN], id[MAXN][2], n1, n2, vs = MAXN-2, vt = MAXN-1;
int c[MAXN][MAXN], fro[MAXN];
bool p[MAX], vis[MAXN];
vector<vector<int> > ans;

bool dfs(int cur) {
    vis[cur] = 1;
    if (cur == vt) return 1;
    for (int i=0; i<MAXN; i++)
        if (c[cur][i] && !vis[i]) {
            fro[i] = cur;
            if (dfs(i)) return 1;
        }
    return 0;
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    for (int i=2; i<MAX; i++) p[i] = 1;
    for (int i=2; i<MAX; i++)
        if (p[i])
            for (int j=i+i; j<MAX; j+=i)
                p[j] = 0;

    cin >> n;
    for (int i=0; i<n; i++) {
        int x; cin >> x;
        if (x%2 == 0) id[n1][0] = i, a[n1++] = x;
        else id[n2][1] = i, b[n2++] = x;
    }
    if (n1 != n2) {
        cout << "Impossible\n";
        return 0;
    }
    int m = n1;

    for (int i=0; i<m; i++)
        for (int j=0; j<m; j++)
            c[i][j+m] = p[a[i]+b[j]];
    for (int i=0; i<m; i++) c[i+m][vt] = 2;
/*
    for (int i=0; i<m; i++) {
        for (int j=m; j<m+m; j++)
            cout << c[i][j] << ' ';
        cout << endl;
    }
*/
    for (int i=0; i<m; i++)
        for (int j=0; j<2; j++) {
            memset(vis, 0, sizeof(vis));
            if (!dfs(i)) {
                cout << "Impossible\n";
                return 0;
            }
            int cur = vt;
            while (cur != i) {
                int nxt = fro[cur];
                c[nxt][cur]--;
                c[cur][nxt]++;
                cur = nxt;
            }
        }
/*
    for (int i=0; i<m; i++) {
        for (int j=m; j<m+m; j++)
            cout << c[i][j] << ' ';
        cout << endl;
    }

    for (int i=m; i<m+m; i++) {
        for (int j=0; j<m; j++)
            cout << c[i][j] << ' ';
        cout << endl;
    }
*/
    memset(vis, 0, sizeof(vis));
    for (int i=0; i<m; i++)
        if (!vis[i]) {
            ans.push_back(vector<int>());
            int cur = i, last = -1, b = 0;
            do {
                ans.back().push_back(id[cur][b]);
                if (!b) {
                    vis[cur] = 1;
                    for (int j=0; j<m; j++)
                        if (!c[cur][j+m] && c[j+m][cur] && j != last) {
                            last = cur;
                            cur = j;
                            break;
                        }
                } else {
                    for (int j=0; j<m; j++)
                        if (c[cur+m][j] && !c[j][cur+m] && j != last) {
                            last = cur;
                            cur = j;
                            break;
                        }
                }
                b = !b;
            } while (b || cur != i);
        }

    cout << ans.size() << '\n';
    for (int i=0; i<ans.size(); i++) {
        cout << ans[i].size() << ' ';
        for (int j=0; j<ans[i].size(); j++)
            cout << ans[i][j]+1 << ' ';
        cout << '\n';
    }
    return 0;
}