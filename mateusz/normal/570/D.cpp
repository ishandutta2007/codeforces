#include <bits/stdc++.h>

using namespace std;

const int N = 500005;

int n, m, par, h, w;
int depth[N];
unsigned long long xors[N];
bool vis[N];
vector<int> V[N];
vector<pair<int, int> > queries[N];
bool ans[N];
char sign[N];

unsigned long long R(unsigned long long x) {
    return (((31413 * x) + 69532) * x + 3168426) * x + 54252524;
}

void DFS(int w) {
    vis[w] = true;
    vector<unsigned long long> currentXors;
    for (int i = 0; i < queries[w].size(); i++) {
        int d = queries[w][i].first;
        currentXors.push_back(xors[d]);
    }

    xors[depth[w]] ^= R(sign[w]);

    for (int i = 0; i < V[w].size(); i++) {
        int u = V[w][i];
        if (vis[u] == false) {
            depth[u] = depth[w] + 1;
            DFS(u);
        }
    }

    for (int i = 0; i < queries[w].size(); i++) {
        int d = queries[w][i].first;
        int in = queries[w][i].second;
        unsigned long long newXor = xors[d] ^ currentXors[i];
        if (newXor == 0) {
            ans[in] = true;
            continue;
        } else {
            for (int j = 0; j < 26; j++) {
                if ((newXor ^ R(j)) == 0) {
                    ans[in] = true;
                    break;
                }
            }
        }
    }
}

int main() {

    scanf("%d %d", &n, &m);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &par);
        V[par].push_back(i);
    }

    scanf("%s", &sign[1]);
    for (int i = 1; i <= n; i++) {
        sign[i] -= 97;
    }

    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &w, &h);
        queries[w].push_back(make_pair(h, i));
    }

    depth[1] = 1;
    DFS(1);

    for (int i = 1; i <= m; i++) {
        printf(ans[i] ? "Yes\n" : "No\n");
    }

    return 0;
}