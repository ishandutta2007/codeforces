#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ios>

using namespace std;

typedef long long ll;

const int maxn = 200100;

int n, x, y;
vector<int> adj[maxn];
int D[maxn][2]; //least number of lines; 0 - line ending at cur

void dfs(int cur, int p = 0) {
    D[cur][0] = D[cur][1] = 1e9;
    vector<int> v;
    int sum = 0;
    for (int i : adj[cur])
        if (i != p) {
            dfs(i, cur);
            sum += D[i][1];
            v.push_back(D[i][0] - D[i][1]);
        }

    sort(v.begin(), v.end());
    if (v.size() == 0) D[cur][0] = 1;
    else if (v.size() == 1) D[cur][0] = min(sum + 1, sum + v[0]);
    else {
        D[cur][0] = sum + 1;
        int sum2 = sum;
        for (int i = 0; i < v.size() && (i < 1 || v[i] < 0); i++)
            sum2 += v[i];
        D[cur][0] = min(D[cur][0], sum2);
        sum2 = sum;
        for (int i = 0; i < v.size() && (i < 2 || v[i] < 0); i++)
            sum2 += v[i];
        D[cur][1] = sum2 - 1;
    }

    D[cur][1] = min(D[cur][1], D[cur][0]);
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> x >> y;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if (x > y) {
        for (int i = 0; i < n; i++)
            if (adj[i].size() == n - 1) {
                cout << x + ll(y) * (n - 2) << '\n';
                return 0;
            }

        cout << ll(y) * (n - 1) << '\n';
        return 0;
    }

    dfs(1);
    int a = min(D[1][0], D[1][1]);
    cout << ll(x) * (n - a) + ll(y) * (a - 1) << '\n';
}