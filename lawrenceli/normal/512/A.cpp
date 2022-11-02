#include <bits/stdc++.h>

using namespace std;

const int MAXN = 105;

int n, indeg[30], ind[30], cnt;
string s[MAXN];
vector<int> adj[30];

void dfs(int cur) {
    ind[cur] = cnt++;
    for (int i=0; i<adj[cur].size(); i++) {
        int nxt = adj[cur][i];
        indeg[nxt]--;
        if (indeg[nxt] == 0) {
            assert(ind[nxt] == -1);
            dfs(nxt);
        }
    }
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) cin >> s[i];
    for (int i=0; i+1<n; i++) {
        int m = min(s[i].length(), s[i+1].length());
        bool b = 0;
        for (int j=0; j<m; j++)
            if (s[i][j] != s[i+1][j]) {
                adj[s[i][j]-'a'].push_back(s[i+1][j]-'a');
                indeg[s[i+1][j]-'a']++;
                b = 1;
                break;
            }
        if (!b) {
            if (s[i].length() > s[i+1].length()) {
                cout << "Impossible\n";
                return 0;
            }
        }
    }

    memset(ind, -1, sizeof(ind));
    for (int i=0; i<26; i++)
        if (ind[i] == -1 && indeg[i] == 0)
            dfs(i);

    for (int i=0; i<26; i++)
        if (ind[i] == -1) {
            cout << "Impossible\n";
            return 0;
        }

    for (int i=0; i<26; i++)
        for (int j=0; j<26; j++)
            if (ind[j] == i)
                cout << char(j+'a');
    return 0;
}