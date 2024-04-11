#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define A first
#define B second

const int maxn = 200100;

int n, k;
vector<int> adj[maxn];
int sub[maxn];
bool in[maxn];

void dfs(int v, int p = -1) {
    sub[v] = in[v];
    for (int i : adj[v])
        if (i != p) {
            dfs(i, v);
            sub[v] += sub[i];
        }
}

int getcen() {
    int v = 1, p = -1;
    while (1) {
        bool good = 1;
        for (int i : adj[v]) {
            if (i == p) continue;
            if (sub[i] >= k) {
                good = 0;
                p = v;
                v = i;
                break;
            }
        }
        if (good) return v;
    }
}

vector<int> stuff[maxn];
int cnt = 1;

void dfs2(int v, int p = -1, int c = 0) {
    if (in[v]) stuff[c].push_back(v);
    for (int i : adj[v])
        if (i != p) {
            int c2 = c ? c : (cnt++);
            dfs2(i, v, c2);
        }
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < 2 * k; i++) {
        int x; cin >> x;
        in[x] = 1;
    }

    dfs(1);
    //for (int i = 1; i <= n; i++) cout << sub[i] << ' '; cout << endl;
    int cen = getcen();
    dfs2(cen);

    priority_queue<pair<int, int> > pq;
    for (int i = 0; i < cnt; i++)
        if (stuff[i].size())
            pq.push(MP(stuff[i].size(), i));

    cout << "1\n" << cen << '\n';

    while (!pq.empty()) {
        pair<int, int> p1 = pq.top(); pq.pop();
        pair<int, int> p2 = pq.top(); pq.pop();

        cout << stuff[p1.B][p1.A - 1] << ' ' << stuff[p2.B][p2.A - 1] << ' ' << cen << '\n';
        if (p1.A > 1) pq.push(MP(p1.A - 1, p1.B));
        if (p2.A > 1) pq.push(MP(p2.A - 1, p2.B));
    }
}