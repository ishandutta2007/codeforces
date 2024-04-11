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

int p[max_n];
int root;
vector<int> v[max_n];
int sz[max_n];

void dfs1(int cur) {
    sz[cur] = 1;
    for (int i = 0; i < v[cur].size(); ++i) {
        int to = v[cur][i];
        dfs1(to);
        sz[cur] += sz[to];
    }
    return;
}

void dfs(int cur) {
    vector<int> bad;
    for (int i = 0; i < v[cur].size(); ++i) {
        int to = v[cur][i];
        if (sz[to] % 2 == 0) {
            dfs(to);
        } else {
            bad.PB(to);
        }
    }
    cout << cur + 1 << "\n";
    for (int i = 0; i < bad.size(); ++i) {
        dfs(bad[i]);
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
        if (p[i] == -1) {
            root = i;
        } else {
            v[p[i]].PB(i);
        }
    }
    dfs1(root);
    dfs(root);

    return 0;
}