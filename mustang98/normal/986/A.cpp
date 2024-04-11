#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, max_k = 111, inf = 1000111222;

vector<int> v[max_n];
vector<int> vc[max_k];
int n, m, s, k;
int col[max_n];

int d_res[max_k][max_n];
int d[max_n];
bool vis[max_n];

void dejkstra(int c)
{
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        d[i] = inf;
        vis[i] = 0;
        if (col[i] == c) {
            d[i] = 0;
            q.push(i);
            vis[i] = 1;
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < v[cur].size(); ++i) {
            int to = v[cur][i];
            if (vis[to]) continue;
            d[to] = d[cur] + 1;
            vis[to] = 1;
            q.push(to);
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> k >> s;
    for (int i = 0; i < n; ++i) {
        scanf("%d", col + i);
        col[i]--;
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a, --b;
        v[a].PB(b);
        v[b].PB(a);
    }
    for (int i = 0; i < k; ++i) {
        dejkstra(i);
        for (int j = 0; j < n; ++j) {
            d_res[i][j] = d[j];
           // cout << d_res[i][j] << ' ';
        }
       // cout << endl;
    }
    for (int i = 0; i < n; ++i) {
        vector<int> ss;
        for (int j = 0; j < k; ++j) {
            ss.PB(d_res[j][i]);
        }
        int ans = 0;
        sort(ss.begin(), ss.end());
        for (int j = 0; j < s; ++j) {
            ans += ss[j];
        }
        printf("%d ", ans);
    }

    return 0;
}