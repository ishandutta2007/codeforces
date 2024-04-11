#include <bits/stdc++.h>

using namespace std;

const int N = 300005, M = 1e9 + 7, P = 257, M2 = 1e9 + 9, P2 = 29;

int n, a, b;
bool vis[N];
int value[N], hashh[N], hashh2[N], dif[N];
char letter[N];
vector<int> V[N];
set<pair<int, int> > S[N];

void DFS(int w) {
    vis[w] = true;
    S[w].insert({hashh[w], hashh2[w]});

    for (int i = 0; i < V[w].size(); i++) {
        int u = V[w][i];
        if (!vis[u]) {
            hashh[u] = ((long long)hashh[w] * P + letter[u]) % M;
            hashh2[u] = ((long long)hashh2[w] * P2 + letter[u]) % M2;
            DFS(u);
            if (S[w].size() < S[u].size()) {
                swap(S[w], S[u]);
            }
            for (auto x : S[u]) {
                S[w].insert(x);
            }
            S[u].clear();
        }
    }

    dif[w] = S[w].size();
}

int main() {

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &value[i]);
    }
    scanf("%s", letter + 1);
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back(b);
        V[b].push_back(a);
    }

    hashh[1] = hashh2[1] = letter[1];
    DFS(1);

    int ans = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int r = dif[i] + value[i];
        if (r == ans) {
            cnt++;
        } else if (r > ans) {
            cnt = 1;
            ans = r;
        }
    }

    printf("%d\n%d\n", ans, cnt);

    return 0;
}