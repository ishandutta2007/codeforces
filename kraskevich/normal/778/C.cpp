#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 3000 * 1000 + 10;
const int A = 26;

int delta[N];
int go[N][A];
int size[N];
int last;

void extend(int v, int other, vector<pii>& actions) {
    for (int c = 0; c < A; c++) 
        if (go[v][c] != -1) {
            if (go[other][c] == -1) {
                actions.push_back(pii(other, c));
                go[other][c] = last++;
            }
            extend(go[v][c], go[other][c], actions); 
        }
}
    
int unite(int a, int b, vector<pii>& actions) {
    if (size[a] < size[b])
        swap(a, b);
    int old_sz = actions.size();
    extend(b, a, actions);
    int new_sz = actions.size();
    size[a] += new_sz - old_sz;
    return a;
}

int dfs(int v, int h) {
    int u = -1;
    size[v] = 1;
    vector<pii> actions;
    for (int c = 0; c < A; c++) {
        if (go[v][c] == -1)
            continue;
        dfs(go[v][c], h + 1);
        size[v] += size[go[v][c]];
        if (u == -1)
            u = go[v][c];
        else
            u = unite(u, go[v][c], actions);
    }
    last -= (int)actions.size();
    for (auto p : actions)
        go[p.first][p.second] = -1;
    if (u != -1)
        delta[h] += size[v] - size[u];
    return size[v];
}
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < N; i++)
        for (int c = 0; c < A; c++)
            go[i][c] = -1;
    for (int i = 0; i < n; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        --a;
        --b;
        go[a][c - 'a'] = b;
    }
    last = n;
    dfs(0, 0);
    auto it = max_element(delta, delta + n);
    cout << n - *it << endl << it - delta + 1 << endl;
}