#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

vector<int> v[max_n];

bool vis[max_n];
bool vis1[max_n];
bool cycle;
bool vis_start;
int start;

void dfs(int a) {
    vis[a] = 1;
    for (int i = 0; i < v[a].size(); ++i) {
        int to = v[a][i];
        if (!vis[to]) dfs(to);
    }
}

bool if_c(int a) {
    int cur = a;
    while (true) {
        vis1[cur] = 1;
        if (v[cur].size() != 2) return false;
        int to1 = v[cur][0];
        int to2 = v[cur][1];
        if (vis1[to1] && !vis1[to2]) {
            cur = to2;
            continue;
        }
        if (!vis1[to1] && vis1[to2]) {
            cur = to1;
            continue;
        }
        if (vis1[to1] && vis1[to2]) {
            if (to1 == a || to2 == a)
            {
                return true;
            } else {
                return false;
            }
        }
        cur = to1;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;;
    for (int i = 0; i < m; ++i) {
        int from, to;
        scanf("%d%d", &from, &to);
        --from, --to;
        v[from].PB(to);
        v[to].PB(from);
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            cnt += if_c(i);
            dfs(i);
        }
    }
cout << cnt;
    return 0;
}