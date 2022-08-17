#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 2111, inf = 1000111222;

int a[max_n];
int b[max_n];
bool vis[max_n];
vector<int> v[max_n];
int n, s;

void add_edge(int a) {
    v[a].PB(n + a);
    v[n + a].PB(a);
}
void dfs(int cur) {
    vis[cur] = 1;
    for (int i =0 ; i < v[cur].size(); ++i) {
        int to = v[cur][i];
        if (!vis[to]) {
            dfs(to);
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    if (a[0] == 0 && b[0] == 0) {
        cout << "NO";
        return 0;
    }
    --s;
    for (int i = 0; i < n; ++i) {
        if (a[i] && b[i]) {
            add_edge(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) continue;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] == 1) {
                v[i].PB(j);
                break;
            }
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        if (b[i] == 0) continue;
        for (int j = i - 1; j >= 0; --j) {
            if (b[j] == 1) {
                v[i + n].PB(j + n);
                break;
            }
        }
    }

    if (a[0]) {
        dfs(0);
    }
    if (b[0]) {
        dfs(n);
    }
    if (vis[s] || vis[s + n]) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}